#ifndef PANTALLA_H
#define PANTALLA_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "modelo.h"
#include "reloj.h"

#define ANCHO 128
#define ALTO 64

extern Adafruit_SSD1306 display;

void iniciarPantalla();

void mostrarPantalla(const PantallaConfig &datos);

// V1.3: se debe llamar en cada vuelta de loop() para animar el
// modoTexto="scroll". No hace nada si el modo actual no es scroll.
void actualizarPantalla();

// V1.8 - Modo 2: pantalla de reloj/estado.
// hayMensajeNuevo: mismo criterio que dispara el buzzer (versión de
//   Firebase cambió y todavía no se "reconoció" visualmente).
// firebaseOk: true si la última consulta a Firebase (obtenerPantalla())
//   fue exitosa.
void mostrarReloj(const EstadoReloj &estado, bool hayMensajeNuevo, bool firebaseOk);

// V1.8 - Modo 3: apaga/enciende el panel físico vía el comando I2C
// del controlador SSD1306 (no solo "pintar en negro"): el panel deja
// de refrescarse, así se ahorra batería de verdad.
void apagarPantallaFisica();
void encenderPantallaFisica();

#endif