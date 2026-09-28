#pragma once
#include <Arduino.h>

// Adafruit GFX n'a que setCursor (coin gauche) : ces fonctions alignent au centre ou a droite.
void ecrireCentre(const char* texte, int16_t xCentre, int16_t y);
void ecrireDroite(const char* texte, int16_t xDroite, int16_t y);

// Texte blanc centre dans un rectangle noir arrondi
void ecrireEnNegatif(const char* texte, int16_t xCentre, int16_t y);

// Les polices GFX n'ont pas le signe degre : on dessine un petit rond au curseur
void ecrireDegre(int16_t rayon, int16_t hauteur);
