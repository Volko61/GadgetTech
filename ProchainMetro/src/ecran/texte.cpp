#include "texte.h"
#include "display.h"

void ecrireCentre(const char* texte, int16_t xCentre, int16_t y) {
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(texte, 0, y, &x1, &y1, &w, &h);
  display.setCursor(xCentre - w / 2 - x1, y);
  display.print(texte);
}

void ecrireDroite(const char* texte, int16_t xDroite, int16_t y) {
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(texte, 0, y, &x1, &y1, &w, &h);
  display.setCursor(xDroite - w - x1, y);
  display.print(texte);
}

void ecrireDegre(int16_t rayon, int16_t hauteur) {
  int16_t x = display.getCursorX();
  int16_t y = display.getCursorY();
  display.drawCircle(x + rayon + 1, y - hauteur + rayon, rayon, GxEPD_BLACK);
  display.setCursor(x + 2 * rayon + 4, y);
}
