#pragma once

// Copier ce fichier en config.h (non commite) et remplir les valeurs.

// Cle d'API PRIM : https://prim.iledefrance-mobilites.fr > Mon compte > Mes jetons d'authentification
#define PRIM_CLE "COLLER_LA_CLE_ICI"

// Metro a surveiller
#define METRO_LIGNE "2"
#define METRO_STATION "Place de Clichy"
#define METRO_ARRET "STIF:StopArea:SP:XXXXX:"  // identifiant de la station, voir le README du dossier
#define METRO_DIRECTION "Nation"               // terminus, tel qu'ecrit par PRIM
#define METRO_MARCHE 5                         // minutes a pied de la maison a la station

// Wi-Fi de la maison
#define WIFI_NOM "NOM_DU_WIFI"
#define WIFI_MDP "MOT_DE_PASSE"
