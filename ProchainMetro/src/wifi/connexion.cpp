#include "connexion.h"
#include "../api/config.h"
#include <WiFi.h>

void wifiConnecter() {
  WiFi.begin(WIFI_NOM, WIFI_MDP);
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
  }
}
