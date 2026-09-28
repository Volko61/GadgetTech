#include "zones.h"
#include "../display.h"
#include "../texte.h"
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>

// Ligne horizontale avec un rond par passage ; le prochain est en negatif.
void dessinerFrise(const Donnees& d) {
  const int16_t yLigne = 226;
  const int16_t xDebut = 132;
  const int16_t ecart = 76;

  display.setFont(&FreeSans9pt7b);
  display.setCursor(10, 204);
  display.print("Prochains");
  display.setCursor(10, 222);
  display.print("metros");

  display.drawFastHLine(xDebut - 30, yLigne, display.width() - xDebut + 20, GxEPD_BLACK);
  display.setFont(&FreeSansBold12pt7b);
  for (int i = 0; i < NB_PASSAGES; i++) {
    int16_t x = xDebut + i * ecart;
    if (i == 0) {
      ecrireEnNegatif(d.passages[i], x, 206);
      display.fillCircle(x, yLigne, 6, GxEPD_BLACK);
    } else {
      ecrireCentre(d.passages[i], x, 206);
      display.fillCircle(x, yLigne, 5, GxEPD_WHITE);
      display.drawCircle(x, yLigne, 5, GxEPD_BLACK);
    }
  }

  display.drawFastHLine(8, 238, display.width() - 16, GxEPD_BLACK);
}
