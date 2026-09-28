#pragma once
#include "donnees.h"

// Donnees factices en attendant les vraies API (RATP, meteo)
const Donnees DONNEES_FAKE = {
  "2",
  "Place de Clichy",
  "10:44",
  "10:52",
  "10:47",
  "dans 3 min",
  5,
  {"10:52", "11:00", "11:08", "11:16"},
  NUAGE,
  18,
  {
    {"Aujourd'hui", SOLEIL_NUAGE, 9, 13},
    {"Demain", PLUIE, 6, 11},
    {"Mercredi", NUAGE, 7, 12},
  },
};
