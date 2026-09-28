#include "donnees_api.h"
#include "../api/config.h"
#include "../api/prim.h"

void donneesDepuisApi(Donnees& d) {
  int minutes[2];
  primProchainsPassages(METRO_ARRET, METRO_DIRECTION, minutes, 2);
  d.ligne = METRO_LIGNE;
  d.station = METRO_STATION;
  d.minutes = minutes[0];
  d.minutesSuivant = minutes[1];
}
