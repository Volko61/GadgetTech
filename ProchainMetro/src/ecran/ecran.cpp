#include "ecran.h"
#include "display.h"
#include "zones/zones.h"

Ecran display(GxEPD2_420_GDEY042T81(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY));

void ecranDemarrer() {
  display.init(115200, true, 2, false);
}

void ecranAfficher(const Donnees& d) {
  display.setFullWindow();
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
  display.hibernate();
}
