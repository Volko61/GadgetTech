#pragma once
#include "donnees.h"

// Remplit tout l'ecran avec les vraies donnees : metro choisi dans la page
// de configuration (API PRIM), heure, et meteo a la station (Open-Meteo).
void donneesDepuisApi(Donnees& d);
