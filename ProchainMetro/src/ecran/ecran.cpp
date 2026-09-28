#include "ecran.h"
#include "display.h"
#include "texte.h"
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSansBold18pt7b.h>
#include <Fonts/FreeSansBold24pt7b.h>

Ecran display(GxEPD2_420_GDEY042T81(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY));

void ecranDemarrer() {
  display.init(115200, true, 2, false);
}

void ecranAfficher(const Donnees& d) {
  int16_t centre = display.width() / 2;
  char texte[32];

  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);

    // Bandeau noir
    display.fillRect(0, 0, display.width(), 60, GxEPD_BLACK);
    display.setTextColor(GxEPD_WHITE);
    display.setFont(&FreeSansBold18pt7b);
    ecrireCentre("Prochain metro", centre, 42);

    display.setTextColor(GxEPD_BLACK);
    display.setFont(&FreeSans12pt7b);
    snprintf(texte, sizeof(texte), "Ligne %s - %s", d.ligne, d.station);
    ecrireCentre(texte, centre, 100);

    // Minutes en grand
    display.setFont(&FreeSansBold24pt7b);
    display.setTextSize(2);
    snprintf(texte, sizeof(texte), "%d min", d.minutes);
    ecrireCentre(texte, centre, 210);
    display.setTextSize(1);

    display.setFont(&FreeSans12pt7b);
    snprintf(texte, sizeof(texte), "puis %d min", d.minutesSuivant);
    ecrireCentre(texte, centre, 265);
  } while (display.nextPage());
}

void ecranEteindre() {
  display.hibernate();
}
