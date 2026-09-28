#pragma once
#include <Arduino.h>

struct Config {
  String ligne;
  String station;
  String arret;  // identifiant PRIM de la station (ex : 71370)
  String direction;
  int marche;    // minutes a pied pour rejoindre la station
  String ville;  // ville pour la meteo
};

extern Config config;

// Lit et ecrit la config dans la memoire interne de l'ESP32
void configCharger();
void configEnregistrer();
