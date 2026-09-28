#pragma once

// Connecte l'ESP32 au Wi-Fi et charge la config de l'utilisateur.
// Au premier demarrage, l'ESP32 cree son propre reseau et affiche sur l'ecran
// un QR code pour s'y connecter. Une page s'ouvre sur le telephone pour choisir
// sa box Wi-Fi et saisir ses metros, son temps de marche et sa ville pour la meteo.
// Tout est enregistre dans la memoire interne pour les demarrages suivants.
// Bloque jusqu'a ce que la connexion soit etablie.
void wifiConnecter();
