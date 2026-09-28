#pragma once
#include "../../donnees/donnees.h"

// Ecran 400x300 decoupe en quatre zones separees par un trait, de haut en bas
void dessinerBandeau(const Donnees& d);  // y 0-84
void dessinerDepart(const Donnees& d);   // y 84-174
void dessinerFrise(const Donnees& d);    // y 174-238
void dessinerMeteo(const Donnees& d);    // y 238-300
