#include "donnees_api.h"
#include "../api/config.h"
#include "../api/prim.h"
#include <time.h>

static char heure[6];
static char metro[6];

// Ecrit l'heure qu'il sera dans "minutes" minutes, par exemple "10:52"
static void heureDans(char* texte, int minutes) {
  time_t t = time(nullptr) + minutes * 60;
  strftime(texte, 6, "%H:%M", localtime(&t));
}

void donneesDepuisApi(Donnees& d) {
  d.ligne = METRO_LIGNE;
  d.station = METRO_STATION;

  // Premier metro qu'on a le temps d'attraper en partant maintenant
  int minutes[10];
  int n = primProchainsPassages(METRO_ARRET, METRO_DIRECTION, minutes, 10);
  int i = 0;
  while (i < n - 1 && minutes[i] < METRO_MARCHE) i++;

  heureDans(heure, 0);
  heureDans(metro, minutes[i]);
  d.heure = heure;
  d.metro = metro;
  d.partirDans = minutes[i] - METRO_MARCHE;
}
