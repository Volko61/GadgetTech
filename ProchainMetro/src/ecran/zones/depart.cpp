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
  display.print(d.partirDans);

  display.setFont(&FreeSansBold24pt7b);
  display.setCursor(display.getCursorX() + 12, 226);
  display.print("min");
}
