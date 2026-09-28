#pragma once
#include "donnees.h"

// Remplit le metro de config.h, l'heure et les prochains passages (API PRIM).
// La meteo n'est pas touchee.
void donneesDepuisApi(Donnees& d);
