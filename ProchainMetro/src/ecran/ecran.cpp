#include "ecran.h"
#include "display.h"
#include "zones/zones.h"

Ecran display(GxEPD2_420_GDEY042T81(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY));

void ecranDemarrer(bool allumage) {
  display.init(115200, allumage, 2, false);
}

void ecranAfficher(const Donnees& d, bool complet) {
  if (complet) display.setFullWindow();
  else display.setPartialWindow(0, 0, display.width(), display.height());
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);
    dessinerBandeau(d);
    dessinerDepart(d);
    dessinerMeteo(d);
  } while (display.nextPage());
}

void ecranEffacer() {
  display.clearScreen();
}

void ecranEteindre() {
  // powerOff et pas hibernate : l'ecran garde l'image en memoire pendant que l'ESP32 dort,
  // le prochain rafraichissement partiel s'en sert.
  display.powerOff();
}
