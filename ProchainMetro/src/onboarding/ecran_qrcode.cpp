#include "ecran_qrcode.h"
#include "../ecran/display.h"
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <qrcode.h>  // generateur de QR code fourni par le core ESP32

static const char* reseauNom;
static const char* reseauMdp;

static void dessiner(esp_qrcode_handle_t qr) {
  int taille = esp_qrcode_get_size(qr);
  int echelle = 260 / taille;
  int x0 = 15;
  int y0 = (display.height() - taille * echelle) / 2;

  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);

    for (int y = 0; y < taille; y++)
      for (int x = 0; x < taille; x++)
        if (esp_qrcode_get_module(qr, x, y))
          display.fillRect(x0 + x * echelle, y0 + y * echelle, echelle, echelle, GxEPD_BLACK);

    display.setTextColor(GxEPD_BLACK);
    display.setFont(&FreeSansBold12pt7b);
    display.setCursor(265, 60);
    display.print("Wi-Fi");

    display.setFont(&FreeSans9pt7b);
    display.setCursor(265, 100);
    display.print("1. Scannez");
    display.setCursor(265, 120);
    display.print("le QR code");
    display.setCursor(265, 150);
    display.print("2. Choisissez");
    display.setCursor(265, 170);
    display.print("votre Wi-Fi");

    display.setCursor(265, 220);
    display.print(reseauNom);
    display.setCursor(265, 240);
    display.print(reseauMdp);
  } while (display.nextPage());
}

void ecranAfficherQrWifi(const char* nom, const char* mdp) {
  reseauNom = nom;
  reseauMdp = mdp;
  String texte = String("WIFI:S:") + nom + ";T:WPA;P:" + mdp + ";;";

  esp_qrcode_config_t config = {};
  config.display_func = dessiner;
  config.max_qrcode_version = 10;
  config.qrcode_ecc_level = ESP_QRCODE_ECC_LOW;
  esp_qrcode_generate(&config, texte.c_str());
}
