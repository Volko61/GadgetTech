#include "zones.h"
#include "../display.h"
#include "../polices/FreeSansBold80pt7b.h"
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSansBold24pt7b.h>

// L'info principale : dans combien de minutes partir de chez soi
void dessinerDepart(const Donnees& d) {
  display.setFont(&FreeSans12pt7b);
  display.setCursor(16, 100);
  display.print("Partir dans");

  display.setFont(&FreeSansBold80pt7b);
  display.setCursor(10, 226);
  if (d.partirDans < 0) {  // pas de metro trouve : la police 80pt n'a que les chiffres, on dessine "--"
    display.fillRect(20, 160, 50, 16, GxEPD_BLACK);
    display.fillRect(84, 160, 50, 16, GxEPD_BLACK);
    display.setCursor(134, 226);
  }
  else display.print(d.partirDans);

  display.setFont(&FreeSansBold24pt7b);
  display.setCursor(display.getCursorX() + 12, 226);
  display.print("min");
}
