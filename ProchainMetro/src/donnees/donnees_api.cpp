#include "donnees_api.h"
#include "../config/config.h"
#include "../api/prim.h"
#include <time.h>
#include <stdio.h>

static char heure[6];
static char partirA[6];
static char partirDans[16];
static char passages[NB_PASSAGES][6];

// Ecrit l'heure qu'il sera dans "minutes" minutes, par exemple "10:52"
static void heureDans(char* texte, int minutes) {
  time_t t = time(nullptr) + minutes * 60;
  strftime(texte, 6, "%H:%M", localtime(&t));
}

void donneesDepuisApi(Donnees& d) {
  Trajet& trajet = config.trajets[0];
  d.ligne = trajet.ligne.c_str();
  d.station = trajet.station.c_str();
  d.marcheMinutes = trajet.marche;
  String arret = String("STIF:StopArea:SP:") + trajet.arret + ":";

  // On ne garde que les metros qu'on a le temps d'attraper en partant maintenant
  int minutes[10];
  int n = primProchainsPassages(arret.c_str(), trajet.direction.c_str(), minutes, 10);
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (minutes[i] >= d.marcheMinutes) minutes[k++] = minutes[i];
  }

  for (int i = 0; i < NB_PASSAGES; i++) {
    if (i < k) heureDans(passages[i], minutes[i]);
    d.passages[i] = passages[i];
  }

  heureDans(heure, 0);
  heureDans(partirA, minutes[0] - d.marcheMinutes);
  snprintf(partirDans, sizeof(partirDans), "dans %d min", minutes[0] - d.marcheMinutes);
  d.heure = heure;
  d.arriveeStation = passages[0];
  d.partirA = partirA;
  d.partirDans = partirDans;
}
