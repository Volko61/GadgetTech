#include "config.h"
#include <Preferences.h>

Config config;
static Preferences memoire;

void configCharger() {
  memoire.begin("config", true);
  config.ligne = memoire.getString("ligne");
  config.station = memoire.getString("station");
  config.arret = memoire.getString("arret");
  config.direction = memoire.getString("direction");
  config.marche = memoire.getInt("marche");
  config.ville = memoire.getString("ville");
  memoire.end();
}

void configEnregistrer() {
  memoire.begin("config", false);
  memoire.putString("ligne", config.ligne);
  memoire.putString("station", config.station);
  memoire.putString("arret", config.arret);
  memoire.putString("direction", config.direction);
  memoire.putInt("marche", config.marche);
  memoire.putString("ville", config.ville);
  memoire.end();
}
