# Module API PRIM

Recupere les prochains passages en temps reel depuis PRIM (Ile-de-France Mobilites).

## Mise en place

1. Creer un compte sur https://prim.iledefrance-mobilites.fr
2. Mon compte > Mes jetons d'authentification > generer une cle d'API.
3. Copier `config.exemple.h` en `config.h` et coller la cle dans `PRIM_CLE`.
   `config.h` est dans le `.gitignore`, il n'est jamais commite.
4. Trouver l'identifiant de la station : sur PRIM, jeu de donnees
   "Referentiel des arrets : Zones d'arrets" (ou "Arrets et lignes associees"),
   chercher "Place de Clichy" et prendre l'identifiant de la zone d'arret
   (un nombre, par exemple 71370). Le mettre dans `METRO_ARRET` sous la forme
   `STIF:StopArea:SP:71370:`.
5. `METRO_DIRECTION` est le terminus du metro, ecrit comme dans la reponse de PRIM
   (champ `DestinationName`), par exemple "Nation" ou "Porte Dauphine" pour la ligne 2.
   Les metros qui partent dans l'autre sens (ou d'une autre ligne) sont ignores.

## Wi-Fi

Remplir aussi `WIFI_NOM` et `WIFI_MDP` dans `config.h` (utilises par `src/wifi/`).

## Utilisation

```cpp
#include "src/api/prim.h"

int minutes[2];
int n = primProchainsPassages(METRO_ARRET, METRO_DIRECTION, minutes, 2);
// minutes[0] : dans combien de minutes part le prochain metro
```

Bibliotheque a installer : ArduinoJson (v7).
