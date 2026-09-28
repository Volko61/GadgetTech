#include "src/donnees/donnees_api.h"
#include "src/ecran/ecran.h"
#include "src/onboarding/onboarding.h"
#include "src/wifi/horloge.h"

void setup() {
  Donnees d;
  ecranDemarrer();  // avant le Wi-Fi : au premier demarrage l'ecran affiche le QR code
  wifiConnecter();
  horlogeRegler();
  donneesDepuisApi(d);

  ecranAfficher(d);
  ecranEteindre();
}

void loop() {
}
