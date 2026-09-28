#include "zones.h"
#include "../display.h"
#include "../icones.h"
#include "../texte.h"
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSansBold18pt7b.h>

// Meteo actuelle a gauche, puis une colonne par jour
void dessinerMeteo(const Donnees& d) {
  iconeMeteo(d.meteo, 30, 266, 18);
  display.setFont(&FreeSansBold18pt7b);
  display.setCursor(56, 284);
  display.print(d.temperature);
  ecrireDegre(3, 25);

  const int16_t xDebut = 116;
  const int16_t largeur = 94;
  display.setFont(&FreeSans9pt7b);
  for (int i = 0; i < NB_JOURS; i++) {
    int16_t x = xDebut + i * largeur;
    int16_t centre = x + largeur / 2;
    display.drawFastVLine(x, 244, 52, GxEPD_BLACK);
    ecrireCentre(d.jours[i].nom, centre, 256);
    iconeMeteo(d.jours[i].meteo, centre, 270, 9);
    display.setCursor(centre - 26, 296);
    display.print(d.jours[i].min);
    ecrireDegre(2, 13);
    display.print(" ");
    display.print(d.jours[i].max);
    ecrireDegre(2, 13);
  }
}
