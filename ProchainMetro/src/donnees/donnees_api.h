#pragma once
#include "donnees.h"

// Remplit le metro choisi dans la page de configuration, l'heure et les prochains passages (API PRIM).
// La meteo n'est pas touchee.
void donneesDepuisApi(Donnees& d);
