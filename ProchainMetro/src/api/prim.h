#pragma once

// Demande a l'API PRIM (Ile-de-France Mobilites) les prochains passages a l'arret
// donne, en ne gardant que les metros qui vont vers direction (ex : "Nation").
// Remplit minutes (dans combien de minutes part chaque metro) et renvoie le nombre trouve.
// Le Wi-Fi doit deja etre connecte (wifiConnecter()).
int primProchainsPassages(const char* arret, const char* direction, int minutes[], int max);
