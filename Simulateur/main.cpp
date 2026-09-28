// Simulateur : meme code d'ecran que l'ESP32, mais le resultat part dans ecran.bmp.
// Pas de Wi-Fi sur le PC : on affiche les donnees factices.
#include "../ProchainMetro/src/donnees/donnees_fake.h"
#include "../ProchainMetro/src/ecran/ecran.h"

int main() {
  ecranDemarrer();
  ecranAfficher(DONNEES_FAKE);
  ecranEteindre();
  return 0;
}
