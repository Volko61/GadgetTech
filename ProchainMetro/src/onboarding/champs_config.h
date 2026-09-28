#pragma once
#include <WiFiManager.h>

// Ajoute les champs de config (metros, temps de marche, meteo) a la page Wi-Fi
void champsAjouter(WiFiManager& wm);

// Recopie ce que l'utilisateur a saisi dans la config
void champsLire();
