#ifndef MODELO_H
#define MODELO_H

#include <Arduino.h>

struct PantallaConfig {

    int version = -1;

    String texto = "";

    int tamano = 1;

    String alineacion = "izquierda";

    // V1.7: alineación vertical del contenido.
    // "centro" (comportamiento de siempre) o "arriba" (pegado al borde superior).
    String alineacionV = "centro";

    bool invertido = false;

    String modoTexto = "ajustar";

    // V1.6: soporte para imágenes monocromáticas.
    // tipo = "texto" (comportamiento actual) o "imagen".
    String tipo = "texto";

    // Bitmap 1bpp empaquetado (mismo formato que Adafruit_GFX::drawBitmap),
    // codificado en Base64 dentro del JSON.
    String imagenData = "";

    int imagenAncho = 0;
    int imagenAlto = 0;

};

// V1.8: modo físico de la pantalla, controlado por el pulsador de D1.
// No tiene nada que ver con "modoTexto" (eso es el layout del
// contenido que llega de Firebase); esto es qué pantalla completa
// se está mostrando en este momento en el dispositivo.
enum ModoPantalla {
    MODO_CONTENIDO = 1, // el contenido de la web, tal como está hoy
    MODO_RELOJ = 2,      // hora/fecha + íconos de wifi/señal/mensaje nuevo
    MODO_APAGADO = 3     // panel OLED apagado de verdad (ahorro de batería)
};

#endif

