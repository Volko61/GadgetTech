#pragma once
#include "../donnees/donnees.h"

// Demande la meteo actuelle de la ville a Open-Meteo (gratuit, sans cle d'API).
// Le Wi-Fi doit deja etre connecte.
void meteoActuelle(const char* ville, Meteo& meteo, int& temperature);
