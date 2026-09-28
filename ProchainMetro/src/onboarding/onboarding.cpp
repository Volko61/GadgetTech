#include "onboarding.h"
#include "ecran_qrcode.h"
#include "champs_config.h"
#include "../config/config.h"
#include <WiFiManager.h>

#define RESEAU_NOM "ProchainMetro"
#define RESEAU_MDP "metro1234"

static void afficherQrCode(WiFiManager*) {
  ecranAfficherQrWifi(RESEAU_NOM, RESEAU_MDP);
}

static void enregistrer() {
  champsLire();
  configEnregistrer();
}

void wifiConnecter() {
  WiFiManager wm;
  wm.setAPCallback(afficherQrCode);
  wm.setSaveConfigCallback(enregistrer);
  champsAjouter(wm);
  wm.autoConnect(RESEAU_NOM, RESEAU_MDP);
  configCharger();
}
