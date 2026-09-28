#include "champs_config.h"
#include "../config/config.h"

static WiFiManagerParameter ligne("ligne", "Ligne (ex : 2)", "", 40);
static WiFiManagerParameter station("station", "Station (ex : Place de Clichy)", "", 40);
static WiFiManagerParameter arret("arret", "Identifiant PRIM de la station (ex : 71370)", "", 40);
static WiFiManagerParameter direction("direction", "Direction (ex : Nation)", "", 40);
static WiFiManagerParameter marche("marche", "Minutes de marche jusqu'a la station", "", 40);
static WiFiManagerParameter ville("ville", "Ville pour la meteo (ex : Paris)", "", 40);
static WiFiManagerParameter titreMetro("<h3>Metro</h3>");
static WiFiManagerParameter titreMeteo("<h3>Meteo</h3>");

void champsAjouter(WiFiManager& wm) {
  wm.addParameter(&titreMetro);
  wm.addParameter(&ligne);
  wm.addParameter(&station);
  wm.addParameter(&arret);
  wm.addParameter(&direction);
  wm.addParameter(&marche);
  wm.addParameter(&titreMeteo);
  wm.addParameter(&ville);
}

void champsLire() {
  config.ligne = ligne.getValue();
  config.station = station.getValue();
  config.arret = arret.getValue();
  config.direction = direction.getValue();
  config.marche = String(marche.getValue()).toInt();
  config.ville = ville.getValue();
}
