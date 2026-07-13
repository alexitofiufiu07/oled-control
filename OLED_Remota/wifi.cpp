#include "wifi.h"

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiManager.h>
#include <LittleFS.h>
#include <ArduinoJson.h>

#include "pantalla.h"

// Acá se guarda la lista de redes que el dispositivo ya aprendió a
// usar (casa, datos del celular, etc). A diferencia de WiFiManager
// solo (que recuerda UNA red y pisa la anterior), acá vamos sumando
// redes nuevas sin borrar las que ya funcionaban.
static const char* ARCHIVO_REDES = "/redes.json";

static const char* NOMBRE_AP = "OLED Remota";
static const unsigned int TIEMPO_PORTAL_SEGUNDOS = 180;

// Cuánto se espera, como máximo, probando las redes ya conocidas
// antes de asumir que ninguna está disponible ahora y abrir el portal.
static const unsigned long TIEMPO_MAX_REDES_CONOCIDAS_MS = 15000;

static ESP8266WiFiMulti wifiMulti;

// ---------------------------------------------------------------
// Lee /redes.json y registra cada red en WiFiMulti para que intente
// conectarse a la que esté disponible. Devuelve cuántas había.
// ---------------------------------------------------------------
static int cargarRedesGuardadas()
{
    if (!LittleFS.exists(ARCHIVO_REDES))
        return 0;

    File archivo = LittleFS.open(ARCHIVO_REDES, "r");
    if (!archivo)
        return 0;

    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, archivo);
    archivo.close();

    if (error || !doc.is<JsonArray>())
        return 0;

    JsonArray redes = doc.as<JsonArray>();
    int cantidad = 0;

    for (JsonObject red : redes)
    {
        const char* ssid = red["ssid"];
        const char* password = red["password"];

        if (ssid && password)
        {
            wifiMulti.addAP(ssid, password);
            cantidad++;
        }
    }

    return cantidad;
}

// ---------------------------------------------------------------
// Agrega una red nueva a /redes.json sin borrar las que ya estaban.
// Si el SSID ya existía (ej: le cambiaron la clave al hotspot),
// actualiza esa entrada en lugar de duplicarla.
// ---------------------------------------------------------------
static void guardarRedNueva(const String &ssid, const String &password)
{
    JsonDocument doc;

    if (LittleFS.exists(ARCHIVO_REDES))
    {
        File archivo = LittleFS.open(ARCHIVO_REDES, "r");
        if (archivo)
        {
            deserializeJson(doc, archivo);
            archivo.close();
        }
    }

    if (!doc.is<JsonArray>())
        doc.to<JsonArray>();

    JsonArray redes = doc.as<JsonArray>();

    for (JsonObject red : redes)
    {
        if (red["ssid"].as<String>() == ssid)
        {
            red["password"] = password;
            File salida = LittleFS.open(ARCHIVO_REDES, "w");
            serializeJson(doc, salida);
            salida.close();
            return;
        }
    }

    JsonObject nueva = redes.add<JsonObject>();
    nueva["ssid"] = ssid;
    nueva["password"] = password;

    File salida = LittleFS.open(ARCHIVO_REDES, "w");
    serializeJson(doc, salida);
    salida.close();
}

void iniciarWiFi()
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("Conectando WiFi...");
    display.display();

    LittleFS.begin();

    int redesGuardadas = cargarRedesGuardadas();

    bool conectado = false;

    // 1) Intenta con las redes ya conocidas (casa, datos, etc).
    if (redesGuardadas > 0)
    {
        unsigned long inicio = millis();

        while (millis() - inicio < TIEMPO_MAX_REDES_CONOCIDAS_MS)
        {
            if (wifiMulti.run() == WL_CONNECTED)
            {
                conectado = true;
                break;
            }
            delay(250);
        }
    }

    // 2) Ninguna red conocida respondió (o es la primera vez):
    //    abre el portal para SUMAR una red nueva a la lista.
    if (!conectado)
    {
        display.clearDisplay();
        display.setCursor(0, 0);
        display.println("Config. WiFi:\n");
        display.println(NOMBRE_AP);
        display.display();

        WiFiManager wm;
        wm.setConfigPortalTimeout(TIEMPO_PORTAL_SEGUNDOS);

        conectado = wm.startConfigPortal(NOMBRE_AP);

        if (conectado)
        {
            guardarRedNueva(WiFi.SSID(), WiFi.psk());
        }
    }

    display.clearDisplay();
    display.setCursor(0, 0);

    if (conectado)
    {
        display.println("WiFi OK");
        display.println(WiFi.SSID());
        display.display();
    }
    else
    {
        display.println("Sin WiFi.");
        display.println("Reiniciando...");
        display.display();
        delay(3000);
        ESP.restart();
    }
}