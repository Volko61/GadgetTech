#pragma once

// Etape 1 : connecte l'ESP32 au Wi-Fi.
// Au premier demarrage, l'ESP32 cree son propre reseau et affiche sur l'ecran
// un QR code pour s'y connecter. Une page s'ouvre sur le telephone pour choisir
// sa box Wi-Fi. Le Wi-Fi est retenu pour les demarrages suivants.
// Bloque jusqu'a ce que la connexion soit etablie.
void wifiConnecter();

// Etape 2 : fait choisir la station, la ligne et la direction.
// L'ecran affiche un QR code vers une page servie par l'ESP32 sur le Wi-Fi de la maison :
// on cherche sa station, on touche sa ligne, on coche ses directions. Rien a recopier.
// Bloque jusqu'a ce que l'utilisateur ait enregistre (la config est alors chargee).
void stationChoisir();
