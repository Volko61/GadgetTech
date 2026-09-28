#include "zones.h"
#include "../display.h"
#include "../texte.h"
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeSansBold18pt7b.h>

void dessinerBandeau(const Donnees& d) {
  // Pastille de la ligne, comme sur les plans du metro
  display.fillCircle(38, 34, 22, GxEPD_BLACK);
  display.setFont(&FreeSansBold18pt7b);
  display.setTextColor(GxEPD_WHITE);
  ecrireCentre(d.ligne, 38, 47);
  display.setTextColor(GxEPD_BLACK);

  display.setFont(&FreeSansBold12pt7b);
  display.setCursor(72, 43);
  display.print(d.station);

  display.setFont(&FreeSans12pt7b);
  ecrireDroite(d.heure, 384, 43);
}
