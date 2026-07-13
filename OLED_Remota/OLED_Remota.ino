#include "config.h"
#include "modelo.h"
#include "github.h"
#include "pantalla.h"
#include "wifi.h"
#include "buzzer.h"
#include "boton.h"
#include "reloj.h"

PantallaConfig pantallaActual;

unsigned long ultimoChequeo = 0;

// V1.1: guarda la versión que ya está dibujada en la OLED,
// para no volver a renderizar si el JSON remoto no cambió.
int versionMostrada = -1;

// V1.8: modo físico actual de la pantalla (contenido / reloj / apagado),
// controlado con el pulsador de D1. Empieza en el modo de siempre.
ModoPantalla modoActual = MODO_CONTENIDO;

// Último resultado de obtenerPantalla(), lo usa el modo reloj para el
// ícono de "conexión con la página web".
bool firebaseOk = false;

// true mientras haya un mensaje nuevo que todavía no se "vio" -- se
// apaga al entrar al modo reloj (eso cuenta como haberlo revisado).
bool mensajeNuevoSinVer = false;

// Cada cuánto se redibuja el modo reloj mientras está activo (no hace
// falta más seguido: reloj.cpp igual solo actualiza la hora 1 vez/seg).
static const unsigned long INTERVALO_REDIBUJO_RELOJ_MS = 1000;
unsigned long ultimoRedibujoReloj = 0;

// ---------------------------------------------------------------
// Cambia de pantalla física y deja todo listo para el nuevo modo:
// apaga/enciende el panel de verdad, y fuerza un primer dibujo para
// no dejar la OLED en blanco hasta el próximo tick del timer.
// ---------------------------------------------------------------
void entrarAModo(ModoPantalla nuevoModo) {

  if (modoActual == MODO_APAGADO && nuevoModo != MODO_APAGADO) {
    encenderPantallaFisica();
  }

  modoActual = nuevoModo;

  if (modoActual == MODO_CONTENIDO) {

    mostrarPantalla(pantallaActual);

  } else if (modoActual == MODO_RELOJ) {

    // Entrar al reloj cuenta como haber revisado el mensaje nuevo.
    mensajeNuevoSinVer = false;

    mostrarReloj(obtenerEstadoReloj(), mensajeNuevoSinVer, firebaseOk);
    ultimoRedibujoReloj = millis();

  } else if (modoActual == MODO_APAGADO) {

    apagarPantallaFisica();

  }

}

ModoPantalla siguienteModo(ModoPantalla modo) {

  if (modo == MODO_CONTENIDO) return MODO_RELOJ;
  if (modo == MODO_RELOJ) return MODO_APAGADO;
  return MODO_CONTENIDO;

}

void setup() {

  Serial.begin(115200);

  iniciarPantalla();

  iniciarBuzzer();

  iniciarBoton();

  // Conecta a la red guardada, o abre el portal de configuración
  // "OLED Remota - Configurar" si es la primera vez que se enciende.
  iniciarWiFi();

  // El reloj necesita la conexión WiFi ya establecida para sincronizar
  // por NTP, por eso se inicia después de iniciarWiFi().
  iniciarReloj();

}

void loop() {

  // --- Estas tres corren siempre, sin importar el modo de pantalla ---
  actualizarBuzzer();
  actualizarReloj();

  // El pulsador de D1 cicla 1 -> 2 -> 3 -> 1 en cada apretón real.
  if (botonPresionado()) {
    entrarAModo(siguienteModo(modoActual));
  }

  // --- Chequeo periódico de Firebase: siempre revisa, sin importar
  //     el modo. Si estamos en modo reloj o apagado, solo se actualiza
  //     el estado en memoria (para el ícono y para cuando se vuelva al
  //     modo contenido); el redibujo real solo pasa en MODO_CONTENIDO,
  //     para no pisar lo que se está mostrando en los otros modos. ---
  if (millis() - ultimoChequeo >= TIEMPO_ACTUALIZACION) {

    ultimoChequeo = millis();

    PantallaConfig nuevaConfig;

    firebaseOk = obtenerPantalla(nuevaConfig);

    if (firebaseOk) {

      // Solo redibuja si la versión cambió respecto a la última mostrada.
      // Esto evita parpadeos innecesarios cuando el JSON remoto sigue igual.
      if (nuevaConfig.version != versionMostrada) {

        // No pitar en el primer chequeo tras encender: en ese momento
        // "versionMostrada" todavía es -1 y no es un mensaje nuevo,
        // es simplemente lo que ya estaba puesto en Firebase.
        bool esPrimeraCarga = (versionMostrada == -1);

        pantallaActual = nuevaConfig;

        if (modoActual == MODO_CONTENIDO) {
          mostrarPantalla(pantallaActual);
        }

        versionMostrada = nuevaConfig.version;

        if (!esPrimeraCarga) {
          notificarMensajeNuevo();
          mensajeNuevoSinVer = true;
        }

      }

    }

  }

  // --- Comportamiento propio de cada modo ---
  if (modoActual == MODO_CONTENIDO) {

    // V1.3: anima el modoTexto="scroll" en cada vuelta del loop.
    // No interfiere con los demás modos ni con el chequeo de arriba.
    actualizarPantalla();

  } else if (modoActual == MODO_RELOJ) {

    if (millis() - ultimoRedibujoReloj >= INTERVALO_REDIBUJO_RELOJ_MS) {
      ultimoRedibujoReloj = millis();
      mostrarReloj(obtenerEstadoReloj(), mensajeNuevoSinVer, firebaseOk);
    }

  }
  // MODO_APAGADO: no hay nada que dibujar, el panel está apagado de verdad.

}
