#ifndef BUZZER_H
#define BUZZER_H

// D2 en el NodeMCU = GPIO4
#define PIN_BUZZER 4

// Configura el pin del buzzer. Llamar una vez desde setup().
void iniciarBuzzer();

// Dispara la secuencia de notificación de "mensaje nuevo" (no bloqueante).
// Si ya había una secuencia sonando, la reinicia desde el principio.
void notificarMensajeNuevo();

// Avanza la secuencia de tonos según el tiempo transcurrido.
// Debe llamarse en cada vuelta de loop(); no bloquea si no hay nada sonando.
void actualizarBuzzer();

#endif