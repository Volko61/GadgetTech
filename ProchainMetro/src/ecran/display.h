#pragma once
#include <GxEPD2_BW.h>

// Broches (DIN = GPIO23 et CLK = GPIO18 sont les broches SPI par defaut)
#define EPD_CS   33
#define EPD_DC   25
#define EPD_RST  26
#define EPD_BUSY 27

// Waveshare 4.2" V2. Pour un V1 : remplacer GxEPD2_420_GDEY042T81 par GxEPD2_420.
using Ecran = GxEPD2_BW<GxEPD2_420_GDEY042T81, GxEPD2_420_GDEY042T81::HEIGHT>;

extern Ecran display;
