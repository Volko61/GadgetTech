#include "config.h"
#include <Preferences.h>

Config config;
static Preferences memoire;

static const char* cle(const char* nom, int i) {
  static String texte;
  texte = String(nom) + i;
  return texte.c_str();
}

void configCharger() {
  memoire.begin("config", true);
  for (int i = 0; i < NB_TRAJETS; i++) {
    config.trajets[i].ligne = memoire.getString(cle("ligne", i));
    config.trajets[i].station = memoire.getString(cle("station", i));
    config.trajets[i].arret = memoire.getString(cle("arret", i));
    config.trajets[i].direction = memoire.getString(cle("direction", i));
    config.trajets[i].marche = memoire.getInt(cle("marche", i));
  }
  config.ville = memoire.getString("ville");
  memoire.end();
}

void configEnregistrer() {
  memoire.begin("config", false);
  for (int i = 0; i < NB_TRAJETS; i++) {
    memoire.putString(cle("ligne", i), config.trajets[i].ligne);
    memoire.putString(cle("station", i), config.trajets[i].station);
    memoire.putString(cle("arret", i), config.trajets[i].arret);
    memoire.putString(cle("direction", i), config.trajets[i].direction);
    memoire.putInt(cle("marche", i), config.trajets[i].marche);
  }
  memoire.putString("ville", config.ville);
  memoire.end();
}
