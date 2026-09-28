#include "src/donnees/donnees_api.h"
#include "src/ecran/ecran.h"
#include "src/wifi/connexion.h"

void setup() {
  Donnees d;
  wifiConnecter();
  donneesDepuisApi(d);

  ecranDemarrer();
  ecranAfficher(d);
  ecranEteindre();
}

void loop() {
}
