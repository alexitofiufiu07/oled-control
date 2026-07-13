#include "github.h"
#include "config.h"

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

bool obtenerPantalla(PantallaConfig &datos)
{

    if (WiFi.status() != WL_CONNECTED)
        return false;

    // V1.8: cliente y conexión HTTPS persistentes entre llamadas.
    //
    // Antes "client" y "http" eran variables locales: se creaban de
    // cero en cada chequeo, lo que obligaba a repetir el handshake TLS
    // completo con Firebase cada 10 segundos (TIEMPO_ACTUALIZACION).
    // Ese handshake bloquea el loop() el tiempo suficiente como para
    // que se note como un "trabón" corto en el scroll cada tantos
    // segundos. Al declararlos "static" se mantienen vivos entre
    // llamadas, y con setReuse(true) la conexión queda en keep-alive:
    // los chequeos siguientes reutilizan la sesión ya abierta en vez
    // de renegociar TLS desde cero, así que son mucho más rápidos y
    // ya no se nota el congelamiento. Si la conexión se cae (WiFi
    // inestable, el servidor la cierra por inactividad, etc.), la
    // librería la reabre sola en el próximo begin().
    static WiFiClientSecure client;
    static HTTPClient http;
    static bool clienteConfigurado = false;

    if (!clienteConfigurado)
    {
        client.setInsecure();
        http.setReuse(true);
        clienteConfigurado = true;
    }

    if (!http.begin(client, url))
        return false;

    int codigo = http.GET();

    if (codigo != HTTP_CODE_OK)
    {
        http.end();
        return false;
    }

    String respuesta = http.getString();

    http.end();

    JsonDocument doc;

    DeserializationError error = deserializeJson(doc, respuesta);

    if (error)
        return false;

    JsonObject pantalla = doc["pantalla"];
    JsonObject config = pantalla["config"];

    datos.version = doc["version"] | 0;

    datos.texto = (const char*)pantalla["texto"];

    datos.tamano = config["tamano"] | 1;

    datos.alineacion = (const char*)config["alineacion"];

    // V1.7: por defecto "centro" para compatibilidad con JSON anteriores.
    datos.alineacionV = (const char*)(config["alineacionV"] | "centro");

    datos.invertido = config["invertido"] | false;

    datos.modoTexto = (const char*)config["modoTexto"];

    // V1.6: tipo = "texto" (por defecto, compatible con JSON anteriores) o "imagen".
    datos.tipo = (const char*)(pantalla["tipo"] | "texto");

    if (datos.tipo == "imagen")
    {
        JsonObject imagen = pantalla["imagen"];

        datos.imagenAncho = imagen["ancho"] | 0;
        datos.imagenAlto = imagen["alto"] | 0;
        datos.imagenData = (const char*)(imagen["datos"] | "");
    }
    else
    {
        datos.imagenAncho = 0;
        datos.imagenAlto = 0;
        datos.imagenData = "";
    }

    return true;
}