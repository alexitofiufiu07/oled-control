#include "buzzer.h"
#include <Arduino.h>

// ---------------------------------------------------------------
// Notificación de "mensaje nuevo": dos beeps cortos y ascendentes,
// con un silencio breve entre medio (estilo "ding-ding" de
// notificación de chat, no una melodía larga). Dura ~240 ms en total.
//
// Se implementa como una máquina de estados no bloqueante: cada
// llamada a actualizarBuzzer() revisa si ya pasó el tiempo del paso
// actual y avanza al siguiente, en vez de usar delay().
// ---------------------------------------------------------------

struct PasoTono {
    unsigned int frecuencia; // Hz. 0 = silencio (no suena, solo espera).
    unsigned int duracion;   // ms que dura este paso.
};

static const PasoTono SECUENCIA[] = {
    {1500, 90},  // beep 1: agudo, corto
    {0,     40}, // silencio breve entre beeps
    {1900, 110}, // beep 2: un poco más agudo, remata el aviso
};

static const int TOTAL_PASOS = sizeof(SECUENCIA) / sizeof(SECUENCIA[0]);

static bool sonando = false;
static int pasoActual = 0;
static unsigned long inicioPaso = 0;

static void iniciarPaso(int indice)
{
    pasoActual = indice;
    inicioPaso = millis();

    if (SECUENCIA[indice].frecuencia > 0)
        tone(PIN_BUZZER, SECUENCIA[indice].frecuencia);
    else
        noTone(PIN_BUZZER);
}

void iniciarBuzzer()
{
    pinMode(PIN_BUZZER, OUTPUT);
    noTone(PIN_BUZZER);
}

void notificarMensajeNuevo()
{
    sonando = true;
    iniciarPaso(0);
}

void actualizarBuzzer()
{
    if (!sonando)
        return;

    if (millis() - inicioPaso < SECUENCIA[pasoActual].duracion)
        return; // todavía no termina este paso

    int siguiente = pasoActual + 1;

    if (siguiente >= TOTAL_PASOS)
    {
        noTone(PIN_BUZZER);
        sonando = false;
        return;
    }

    iniciarPaso(siguiente);
}