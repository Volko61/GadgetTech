#pragma once

#define NB_PASSAGES 4
#define NB_JOURS 3

enum Meteo { SOLEIL, NUAGE, SOLEIL_NUAGE, PLUIE };

struct Jour {
  const char* nom;
  Meteo meteo;
  int min;
  int max;
};

struct Donnees {
  const char* ligne;
  const char* station;
  const char* heure;
  const char* arriveeStation;
  const char* partirA;
  const char* partirDans;
  int marcheMinutes;
  const char* passages[NB_PASSAGES];
  Meteo meteo;
  int temperature;
  Jour jours[NB_JOURS];
};
