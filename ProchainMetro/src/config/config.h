#pragma once
#include <Arduino.h>

#define NB_TRAJETS 2

struct Trajet {
  String ligne;
  String station;
  String arret;  // identifiant PRIM de la station (ex : 71370)
  String direction;
  int marche;  // minutes a pied pour rejoindre la station
};

struct Config {
  Trajet trajets[NB_TRAJETS];
  String ville;  // ville pour la meteo, vide = pas de meteo
};

extern Config config;

// Lit et ecrit la config dans la memoire interne de l'ESP32
void configCharger();
void configEnregistrer();
