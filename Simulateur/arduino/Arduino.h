#pragma once
// Remplace le Arduino.h de l'ESP32 pour compiler sur PC
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Print.h"

#define PROGMEM
#ifndef PI
#define PI 3.14159265358979f
#endif
#define radians(deg) ((deg) * PI / 180)

// Declares par Adafruit GFX, pas utilises par ProchainMetro
class __FlashStringHelper;
class String {
public:
  unsigned int length() const { return 0; }
  const char* c_str() const { return ""; }
};
