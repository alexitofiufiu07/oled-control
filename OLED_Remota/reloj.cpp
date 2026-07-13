#include "reloj.h"

#include <ESP8266WiFi.h>
#include <time.h>

// Colombia: UTC-5 todo el año, sin horario de verano.
static const long GMT_OFFSET_SEG = -5 * 3600;
static const int DST_OFFSET_SEG = 0;

static const char *SERVIDOR_NTP_1 = "pool.ntp.org";
static const char *SERVIDOR_NTP_2 = "time.google.com";

// Cada cuánto se relee el reloj del sistema (operación instantánea,
// no es una petición de red -- una vez que configTime() sincronizó,
// time() ya devuelve la hora calculada localmente).
static const unsigned long INTERVALO_HORA_MS = 1000;

// Cada cuánto se recalculan las barras de señal. No hace falta más
// seguido: la intensidad de la señal WiFi no cambia tan rápido.
static const unsigned long INTERVALO_SENAL_MS = 5000;

static EstadoReloj estado;
static unsigned long ultimaLecturaHora = 0;
static unsigned long ultimaLecturaSenal = 0;
static bool ntpConfigurado = false;

// Convierte RSSI (dBm, típicamente entre -30 y -90) a 0-4 barras,
// con los mismos cortes que suele usar el ícono de señal de un celular.
static int rssiABarras(int32_t rssi)
{
    if (rssi >= -55) return 4;
    if (rssi >= -65) return 3;
    if (rssi >= -75) return 2;
    if (rssi >= -85) return 1;
    return 0;
}

void iniciarReloj()
{
    // configTime() dispara la sincronización SNTP en segundo plano;
    // no bloquea el arranque. El resultado se revisa recién en
    // actualizarReloj(), cuando time() ya tenga una fecha válida.
    configTime(GMT_OFFSET_SEG, DST_OFFSET_SEG, SERVIDOR_NTP_1, SERVIDOR_NTP_2);
    ntpConfigurado = true;
}

void actualizarReloj()
{
    unsigned long ahora = millis();

    if (ahora - ultimaLecturaHora >= INTERVALO_HORA_MS)
    {
        ultimaLecturaHora = ahora;

        estado.wifiConectado = (WiFi.status() == WL_CONNECTED);

        if (ntpConfigurado)
        {
            time_t t = time(nullptr);

            // Antes de la primera sincronización, time() devuelve un
            // valor muy chico (1-1-1970). Se descarta hasta que el
            // NTP haya respondido de verdad al menos una vez.
            if (t > 1700000000) // cualquier fecha "razonable" de acá en adelante
            {
                struct tm horaLocal;
                localtime_r(&t, &horaLocal);

                estado.horaValida = true;
                estado.hora = horaLocal.tm_hour;
                estado.minuto = horaLocal.tm_min;
                estado.dia = horaLocal.tm_mday;
                estado.mes = horaLocal.tm_mon + 1;
                estado.anio = horaLocal.tm_year + 1900;
            }
        }
    }

    if (ahora - ultimaLecturaSenal >= INTERVALO_SENAL_MS)
    {
        ultimaLecturaSenal = ahora;

        estado.barrasSenal = estado.wifiConectado ? rssiABarras(WiFi.RSSI()) : 0;
    }
}

EstadoReloj obtenerEstadoReloj()
{
    return estado;
}