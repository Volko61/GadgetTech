# Simulateur d'ecran

Fait tourner le code d'affichage sur le PC, sans ESP32 ni ecran e-ink.
Le dessin est enregistre dans `ecran.bmp` (400x300, noir et blanc).

Le croquis `HelloWorld` est compile tel quel :
seul GxEPD2 est remplace par un canvas Adafruit GFX (`gxepd2/GxEPD2_BW.h`).

## Prerequis

- g++ (Windows : `winget install BrechtSanders.WinLibs.POSIX.UCRT`, puis rouvrir le terminal)
- La bibliotheque Adafruit GFX deja installee pour Arduino
  (`Documents\Arduino\libraries\Adafruit_GFX_Library`)

## Lancer

Windows, depuis le dossier `Simulateur` :

    compiler.bat

Linux / Mac :

    ./compiler.sh ~/Arduino/libraries

## Organisation

- `main.cpp` : inclut le croquis et appelle `setup()` comme l'ESP32
- `gxepd2/` : faux GxEPD2 (meme nom de classe et memes fonctions)
- `arduino/` : faux `Arduino.h` et `Print.h`, juste ce qu'Adafruit GFX demande
- `image/` : ecriture du fichier BMP
