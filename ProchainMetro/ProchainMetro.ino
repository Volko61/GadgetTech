// Carte : ESP32 Dev Module
// Outils > Partition Scheme : "Minimal SPIFFS (1.9MB APP with OTA/128KB SPIFFS)"
// (le programme ne tient plus dans les 1,2 Mo du schema par defaut)
#include "src/donnees/donnees_fake.h"
#include "src/donnees/donnees_api.h"
#include "src/ecran/ecran.h"
#include "src/onboarding/onboarding.h"
#include "src/config/config.h"
#include "src/wifi/horloge.h"

void setup() {
  Donnees d = DONNEES_FAKE;  // valeurs par defaut si une API ne repond pas
  ecranDemarrer();  // avant le Wi-Fi : au premier demarrage l'ecran affiche les QR codes
  wifiConnecter();
  horlogeRegler();
  if (!configCharger()) stationChoisir();
  donneesDepuisApi(d);
  ecranAfficher(d);
  ecranEteindre();
}

void loop() {
}
