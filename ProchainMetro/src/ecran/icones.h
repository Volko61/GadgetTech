#pragma once
#include <Arduino.h>
#include "../donnees/donnees.h"

// Icones dessinees avec les formes de base d'Adafruit GFX
void iconeMetro(int16_t x, int16_t y);                         // 40x54, coin haut gauche
void iconeMarcheur(int16_t x, int16_t y);                      // 24x40, coin haut gauche
void iconeMeteo(Meteo meteo, int16_t cx, int16_t cy, int16_t r);  // centree, r = demi-largeur
