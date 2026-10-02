#include "donnees_api.h"
#include "../config/config.h"
#include "../api/prim.h"
#include "../api/meteo.h"
#include <time.h>
#include <algorithm>

#define MAX_PASSAGES 20

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

  // Les passages de notre ligne vers une des directions choisies, a chacun de nos arrets
  int minutes[MAX_PASSAGES];
  int n = 0;
  String directions = "|" + config.directions + "|";
  int debut = 0;
  while (debut < (int)config.arrets.length()) {
    int fin = config.arrets.indexOf(',', debut);
    if (fin < 0) fin = config.arrets.length();
    String arret = config.arrets.substring(debut, fin);
    debut = fin + 1;

    primPassages(arret.c_str(), [&](const char* ligne, const char* destination, int m) {
      if (n < MAX_PASSAGES && config.ligneRef == ligne && directions.indexOf("|" + String(destination) + "|") >= 0)
        minutes[n++] = m;
    });
  }
  std::sort(minutes, minutes + n);

  // Premier metro qu'on a le temps d'attraper en partant maintenant
  int i = 0;
  while (i < n && minutes[i] < config.marche) i++;

  heureDans(heure, 0);
  d.heure = heure;
  if (i == n) {  // aucun metro (nuit, erreur PRIM) : l'ecran affiche "--"
    d.metro = "--:--";
    d.partirDans = -1;
  } else {
    heureDans(metro, minutes[i]);
    d.metro = metro;
    d.partirDans = minutes[i] - config.marche;
  }
  Serial.printf("[DONNEES] %d passage(s), partir dans %d min\n", n, d.partirDans);

  meteoActuelle(config.latitude, config.longitude, d.meteo, d.temperature);
}
