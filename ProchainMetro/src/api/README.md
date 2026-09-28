# Module API PRIM

Recupere les prochains passages en temps reel depuis PRIM (Ile-de-France Mobilites).

## Cle d'API

1. Creer un compte sur https://prim.iledefrance-mobilites.fr
2. Mon compte > Mes jetons d'authentification > generer une cle d'API.
3. Copier `cle.exemple.h` en `cle.h` et coller la cle dans `PRIM_CLE`.
   `cle.h` est dans le `.gitignore`, il n'est jamais commite.

## Ce que l'utilisateur saisit dans la page de configuration

- Identifiant PRIM de la station : sur PRIM, jeu de donnees
  "Referentiel des arrets : Zones d'arrets" (ou "Arrets et lignes associees"),
  chercher sa station et prendre l'identifiant de la zone d'arret (un nombre, par exemple 71370).
- Direction : le terminus du metro, ecrit comme dans la reponse de PRIM
  (champ `DestinationName`), par exemple "Nation" ou "Porte Dauphine" pour la ligne 2.
  Les metros qui partent dans l'autre sens (ou d'une autre ligne) sont ignores.
- Minutes de marche : les metros qu'on n'a plus le temps d'attraper ne sont pas affiches.

## Utilisation

```cpp
#include "src/api/prim.h"

int minutes[2];
int n = primProchainsPassages("STIF:StopArea:SP:71370:", "Nation", minutes, 2);
// minutes[0] : dans combien de minutes part le prochain metro
```

Bibliotheque a installer : ArduinoJson (v7).
