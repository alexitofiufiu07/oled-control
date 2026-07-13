#ifndef BOTON_H
#define BOTON_H

#include <Arduino.h>

// D1 en el NodeMCU = GPIO5.
// Cableado esperado: pulsador entre D1 y GND, con INPUT_PULLUP
// (no hace falta resistencia externa) -- presionado = LOW.
#define PIN_BOTON 5

// Cuánto tiempo se ignoran cambios de estado después de detectar uno,
// para filtrar el "rebote" mecánico del pulsador (ruido eléctrico de
// unos pocos milisegundos al hacer contacto). No es un delay(): se
// compara contra millis() en cada llamada a botonPresionado().
static const unsigned long BOTON_ANTIRREBOTE_MS = 50;

// Configura el pin del pulsador. Llamar una vez desde setup().
void iniciarBoton();

// Debe llamarse en cada vuelta de loop(). No bloquea.
// Devuelve true UNA sola vez por cada pulsación real (ya filtrada de
// rebotes), justo en el momento en que se presiona el botón -- no
// mientras se mantiene apretado, y no al soltarlo. Así el .ino puede
// simplemente hacer:
//
//   if (botonPresionado()) {
//     modoActual = siguienteModo(modoActual);
//   }
//
// sin preocuparse de que un solo apretón cicle varias veces el modo.
bool botonPresionado();

#endif