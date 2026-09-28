#pragma once

struct Donnees {
  const char* ligne;
  const char* station;
  int minutes;          // prochain metro
  int minutesSuivant;   // metro d'apres
};
