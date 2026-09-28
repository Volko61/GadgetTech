#include "champs_config.h"
#include "../config/config.h"

static const char* titres[NB_TRAJETS] = {"<h3>Metro 1</h3>", "<h3>Metro 2 (facultatif)</h3>"};
static const char* ids[NB_TRAJETS][5] = {
  {"ligne0", "station0", "arret0", "direction0", "marche0"},
  {"ligne1", "station1", "arret1", "direction1", "marche1"},
};
static const char* libelles[5] = {"Ligne (ex : 2)", "Station (ex : Place de Clichy)", "Identifiant PRIM de la station (ex : 71370)", "Direction (ex : Nation)", "Minutes de marche jusqu'a la station"};

static WiFiManagerParameter* champs[NB_TRAJETS][5];
static WiFiManagerParameter* ville;

void champsAjouter(WiFiManager& wm) {
  for (int i = 0; i < NB_TRAJETS; i++) {
    wm.addParameter(new WiFiManagerParameter(titres[i]));
    for (int j = 0; j < 5; j++) {
      champs[i][j] = new WiFiManagerParameter(ids[i][j], libelles[j], "", 40);
      wm.addParameter(champs[i][j]);
    }
  }
  wm.addParameter(new WiFiManagerParameter("<h3>Meteo</h3>"));
  ville = new WiFiManagerParameter("ville", "Ville (laisser vide pour ne pas afficher la meteo)", "", 40);
  wm.addParameter(ville);
}

void champsLire() {
  for (int i = 0; i < NB_TRAJETS; i++) {
    config.trajets[i].ligne = champs[i][0]->getValue();
    config.trajets[i].station = champs[i][1]->getValue();
    config.trajets[i].arret = champs[i][2]->getValue();
    config.trajets[i].direction = champs[i][3]->getValue();
    config.trajets[i].marche = String(champs[i][4]->getValue()).toInt();
  }
  config.ville = ville->getValue();
}
