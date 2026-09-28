#include "prim.h"
#include "config.h"
#include "heure.h"
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

#define PRIM_URL "https://prim.iledefrance-mobilites.fr/marketplace/stop-monitoring"

int primProchainsPassages(const char* arret, const char* direction, int minutes[], int max) {
  WiFiClientSecure client;
  client.setInsecure();  // pas de verification du certificat

  HTTPClient http;
  http.begin(client, String(PRIM_URL) + "?MonitoringRef=" + arret);
  http.addHeader("apikey", PRIM_CLE);
  http.GET();

  // On ne garde que les champs utiles de la reponse SIRI
  JsonDocument filtre;
  filtre["Siri"]["ServiceDelivery"]["ResponseTimestamp"] = true;
  JsonObject f = filtre["Siri"]["ServiceDelivery"]["StopMonitoringDelivery"][0]["MonitoredStopVisit"][0]["MonitoredVehicleJourney"].to<JsonObject>();
  f["DestinationName"][0]["value"] = true;
  f["MonitoredCall"]["ExpectedDepartureTime"] = true;

  JsonDocument doc;
  deserializeJson(doc, http.getString(), DeserializationOption::Filter(filtre));
  http.end();

  JsonObject livraison = doc["Siri"]["ServiceDelivery"];
  int maintenant = heureEnSecondes(livraison["ResponseTimestamp"]);
  JsonArray visites = livraison["StopMonitoringDelivery"][0]["MonitoredStopVisit"];

  int n = 0;
  for (JsonObject visite : visites) {
    if (n == max) break;
    JsonObject trajet = visite["MonitoredVehicleJourney"];
    if (strcmp(trajet["DestinationName"][0]["value"], direction) != 0) continue;  // metro dans l'autre sens
    minutes[n] = (heureEnSecondes(trajet["MonitoredCall"]["ExpectedDepartureTime"]) - maintenant) / 60;
    n++;
  }
  return n;
}
