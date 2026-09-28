#include "src/donnees/donnees_fake.h"
#include "src/donnees/donnees_api.h"
#include "src/ecran/ecran.h"
#include "src/wifi/connexion.h"
#include "src/wifi/horloge.h"

void setup() {
  Donnees d = DONNEES_FAKE;  // la meteo reste factice en attendant son API
  wifiConnecter();
  horlogeRegler();
  donneesDepuisApi(d);

  ecranDemarrer();
  ecranAfficher(d);
  ecranEteindre();
}

void loop() {
}
