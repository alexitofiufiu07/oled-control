#ifndef RELOJ_H
#define RELOJ_H

#include <Arduino.h>

// ---------------------------------------------------------------
// Modo 2 (pantalla "reloj"): este módulo SOLO calcula datos
// (hora, fecha, señal WiFi). No dibuja nada en la OLED -- eso lo
// hace pantalla.cpp, igual que con PantallaConfig.
// ---------------------------------------------------------------
struct EstadoReloj {

    // false hasta que el NTP sincronice por primera vez (ej. recién
    // encendido, todavía sin respuesta del servidor). pantalla.cpp
    // debe revisar este campo antes de dibujar la hora.
    bool horaValida = false;

    int hora = 0;    // 0-23
    int minuto = 0;  // 0-59

    int dia = 0;     // 1-31
    int mes = 0;     // 1-12
    int anio = 0;    // ej. 2026

    bool wifiConectado = false;
    int barrasSenal = 0; // 0-4, ya mapeado desde el RSSI (0 = sin señal)
};

// Configura la sincronización NTP (zona horaria Colombia, UTC-5,
// sin horario de verano). No bloquea. Llamar una vez desde setup(),
// después de iniciarWiFi() (necesita la conexión ya establecida).
void iniciarReloj();

// Debe llamarse en cada vuelta de loop(). Internamente decide cada
// cuánto vale la pena releer el reloj del sistema / el RSSI -- no
// hace ninguna petición de red pesada en cada llamada, así que es
// seguro llamarla siempre, sin importar el modo de pantalla activo.
void actualizarReloj();

// Devuelve el último estado calculado. Es instantáneo (solo lee
// variables en memoria), lo puede llamar pantalla.cpp cada vez que
// necesite redibujar el modo reloj.
EstadoReloj obtenerEstadoReloj();

#endif