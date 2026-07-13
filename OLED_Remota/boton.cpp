#include "boton.h"

// Estado crudo la última vez que se leyó el pin (para detectar el
// flanco de "recién presionado", no el nivel sostenido).
static int ultimoEstadoCrudo = HIGH;

// Último estado ya filtrado de rebotes, es el que se compara contra
// el crudo para decidir si el cambio fue real o solo ruido.
static int ultimoEstadoEstable = HIGH;

static unsigned long ultimoCambio = 0;

void iniciarBoton()
{
    pinMode(PIN_BOTON, INPUT_PULLUP);

    ultimoEstadoCrudo = digitalRead(PIN_BOTON);
    ultimoEstadoEstable = ultimoEstadoCrudo;
    ultimoCambio = millis();
}

bool botonPresionado()
{
    int lecturaActual = digitalRead(PIN_BOTON);

    if (lecturaActual != ultimoEstadoCrudo)
    {
        // El pin cambió respecto a la lectura anterior: podría ser un
        // apretón real o rebote mecánico. Se reinicia el cronómetro y
        // se espera a que el nivel se mantenga quieto un rato antes
        // de darlo por bueno.
        ultimoEstadoCrudo = lecturaActual;
        ultimoCambio = millis();
    }

    bool presionEnEsteCiclo = false;

    if ((millis() - ultimoCambio) >= BOTON_ANTIRREBOTE_MS)
    {
        // El nivel ya estuvo quieto el tiempo suficiente: se lo acepta
        // como el nuevo estado estable.
        if (lecturaActual != ultimoEstadoEstable)
        {
            ultimoEstadoEstable = lecturaActual;

            // Con INPUT_PULLUP, presionado = LOW. Solo cuenta como
            // "presionado" el flanco de HIGH -> LOW (el momento exacto
            // en que se hace contacto), no cuando se suelta.
            if (ultimoEstadoEstable == LOW)
            {
                presionEnEsteCiclo = true;
            }
        }
    }

    return presionEnEsteCiclo;
}