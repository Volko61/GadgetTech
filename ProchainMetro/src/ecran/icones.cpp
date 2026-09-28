#include "icones.h"
#include "display.h"

void iconeMetro(int16_t x, int16_t y) {
  display.fillRoundRect(x, y, 40, 46, 8, GxEPD_BLACK);
  display.fillRect(x + 6, y + 7, 28, 16, GxEPD_WHITE);
  display.fillCircle(x + 11, y + 35, 3, GxEPD_WHITE);
  display.fillCircle(x + 29, y + 35, 3, GxEPD_WHITE);
  display.drawLine(x + 8, y + 46, x + 2, y + 54, GxEPD_BLACK);
  display.drawLine(x + 32, y + 46, x + 38, y + 54, GxEPD_BLACK);
}

void iconeMarcheur(int16_t x, int16_t y) {
  display.fillCircle(x + 14, y + 4, 4, GxEPD_BLACK);
  for (int e = 0; e < 2; e++) {  // traits doubles pour les epaissir
    display.drawLine(x + 13 + e, y + 10, x + 10 + e, y + 24, GxEPD_BLACK);  // corps
    display.drawLine(x + 12 + e, y + 13, x + 4 + e, y + 20, GxEPD_BLACK);   // bras arriere
    display.drawLine(x + 12 + e, y + 13, x + 20 + e, y + 19, GxEPD_BLACK);  // bras avant
    display.drawLine(x + 10 + e, y + 24, x + 3 + e, y + 38, GxEPD_BLACK);   // jambe arriere
    display.drawLine(x + 10 + e, y + 24, x + 18 + e, y + 38, GxEPD_BLACK);  // jambe avant
  }
}

static void soleil(int16_t cx, int16_t cy, int16_t r) {
  display.fillCircle(cx, cy, r / 2, GxEPD_BLACK);
  for (int i = 0; i < 8; i++) {
    float a = i * PI / 4;
    display.drawLine(cx + cos(a) * r * 0.7, cy + sin(a) * r * 0.7, cx + cos(a) * r, cy + sin(a) * r, GxEPD_BLACK);
  }
}

static void nuage(int16_t cx, int16_t cy, int16_t r) {
  int16_t p = r / 2;
  display.fillCircle(cx - p, cy + p / 2, p, GxEPD_BLACK);
  display.fillCircle(cx + p, cy + p / 2, p, GxEPD_BLACK);
  display.fillCircle(cx, cy, r * 2 / 3, GxEPD_BLACK);
  display.fillRect(cx - p, cy + p / 2, 2 * p, p, GxEPD_BLACK);
}

void iconeMeteo(Meteo meteo, int16_t cx, int16_t cy, int16_t r) {
  switch (meteo) {
    case SOLEIL:
      soleil(cx, cy, r);
      break;
    case NUAGE:
      nuage(cx, cy, r);
      break;
    case SOLEIL_NUAGE:
      soleil(cx - r / 3, cy - r / 3, r * 2 / 3);
      nuage(cx + r / 4, cy + r / 4, r * 3 / 4);
      break;
    case PLUIE:
      nuage(cx, cy - r / 3, r * 3 / 4);
      for (int i = -1; i <= 1; i++) {
        display.drawLine(cx + i * r / 2, cy + r / 2, cx + i * r / 2 - 3, cy + r, GxEPD_BLACK);
      }
      break;
  }
}
