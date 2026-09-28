#include "meteo.h"
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

static void lireJson(String url, JsonDocument& doc) {
  WiFiClientSecure client;
  client.setInsecure();  // pas de verification du certificat
  HTTPClient http;
  http.begin(client, url);
  http.GET();
  deserializeJson(doc, http.getString());
  http.end();
}

// Code meteo WMO d'Open-Meteo vers nos quatre icones
static Meteo icone(int code) {
  if (code <= 1) return SOLEIL;
  if (code == 2) return SOLEIL_NUAGE;
  if (code <= 48) return NUAGE;
  return PLUIE;  // pluie, neige, orage
}

void meteoActuelle(const char* ville, Meteo& meteo, int& temperature) {
  JsonDocument lieu;
  lireJson(String("https://geocoding-api.open-meteo.com/v1/search?count=1&name=") + ville, lieu);
  float latitude = lieu["results"][0]["latitude"];
  float longitude = lieu["results"][0]["longitude"];

  JsonDocument doc;
  lireJson(String("https://api.open-meteo.com/v1/forecast?current=temperature_2m,weather_code&latitude=")
    + latitude + "&longitude=" + longitude, doc);
  temperature = round(doc["current"]["temperature_2m"].as<float>());
  meteo = icone(doc["current"]["weather_code"]);
}
