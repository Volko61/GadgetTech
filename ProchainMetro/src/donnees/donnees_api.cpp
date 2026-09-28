#include "donnees_api.h"
#include "../config/config.h"
#include "../api/prim.h"
#include "../api/meteo.h"
#include <time.h>

static char heure[6];
static char metro[6];

// Ecrit l'heure qu'il sera dans "minutes" minutes, par exemple "10:52"
static void heureDans(char* texte, int minutes) {
  time_t t = time(nullptr) + minutes * 60;
  strftime(texte, 6, "%H:%M", localtime(&t));
}

void donneesDepuisApi(Donnees& d) {
  d.ligne = config.ligne.c_str();
  d.station = config.station.c_str();
  String arret = String("STIF:StopArea:SP:") + config.arret + ":";

  // Premier metro qu'on a le temps d'attraper en partant maintenant
  int minutes[10];
  int n = primProchainsPassages(arret.c_str(), config.direction.c_str(), minutes, 10);
  int i = 0;
  while (i < n - 1 && minutes[i] < config.marche) i++;

  heureDans(heure, 0);
  heureDans(metro, minutes[i]);
  d.heure = heure;
  d.metro = metro;
  d.partirDans = minutes[i] - config.marche;

  meteoActuelle(config.ville.c_str(), d.meteo, d.temperature);
}
