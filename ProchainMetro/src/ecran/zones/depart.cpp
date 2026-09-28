#include "zones.h"
#include "../display.h"
#include "../icones.h"
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSansBold18pt7b.h>
#include <Fonts/FreeSansBold24pt7b.h>

void dessinerDepart(const Donnees& d) {
  display.setFont(&FreeSans9pt7b);
  display.setCursor(10, 106);
  display.print("Partir de chez soi");
  display.setFont(&FreeSansBold24pt7b);
  display.setCursor(10, 147);
  display.print(d.partirA);
  display.setFont(&FreeSans9pt7b);
  display.setCursor(10, 166);
  display.print(d.partirDans);

  // Encadre du temps de marche
  display.drawRoundRect(216, 94, 176, 72, 8, GxEPD_BLACK);
  iconeMarcheur(228, 110);
  display.setFont(&FreeSansBold18pt7b);
  display.setCursor(262, 126);
  display.print(d.marcheMinutes);
  display.print(" min");
  display.setFont(&FreeSans9pt7b);
  display.setCursor(262, 144);
  display.print("pour rejoindre");
  display.setCursor(262, 159);
  display.print("la station");

  display.drawFastHLine(8, 174, display.width() - 16, GxEPD_BLACK);
}
