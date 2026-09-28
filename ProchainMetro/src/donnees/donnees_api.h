#pragma once
#include "donnees.h"

// Remplit tout l'ecran avec les vraies donnees : metro choisi dans la page
// de configuration (API PRIM), heure, et meteo de la ville (Open-Meteo).
void donneesDepuisApi(Donnees& d);
