#ifndef WIFI_H
#define WIFI_H

// Conecta a la red WiFi guardada en la memoria del ESP8266.
// Si es la primera vez (o la conexión falla), levanta un punto de
// acceso de configuración para que el usuario cargue su propia red
// desde el celular, sin tocar el código ni reflashear.
void iniciarWiFi();

#endif