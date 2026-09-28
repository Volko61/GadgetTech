#include "zones.h"
#include "../display.h"
#include "../icones.h"
#include "../texte.h"
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeSansBold18pt7b.h>

void dessinerBandeau(const Donnees& d) {
  iconeMetro(10, 12);

  display.setFont(&FreeSans9pt7b);
  display.setCursor(62, 28);
  display.print(d.station);
  display.setFont(&FreeSansBold18pt7b);
  display.setCursor(62, 62);
  display.print("Ligne ");
  display.print(d.ligne);

  display.setFont(&FreeSansBold12pt7b);
  ecrireEnNegatif(d.heure, 356, 26);
  display.setFont(&FreeSans9pt7b);
  ecrireDroite("Arrivee a la station", 392, 52);
  display.setFont(&FreeSansBold18pt7b);
  ecrireDroite(d.arriveeStation, 392, 80);

  display.drawFastHLine(8, 86, display.width() - 16, GxEPD_BLACK);
}
