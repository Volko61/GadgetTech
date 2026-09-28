@echo off
rem Compile et lance le simulateur, puis ouvre ecran.bmp
rem Dossier des bibliotheques Arduino (celui ou est installe Adafruit GFX)
set LIBS=%USERPROFILE%\Documents\Arduino\libraries
set GFX=%LIBS%\Adafruit_GFX_Library

set SOURCES=main.cpp image\bmp.cpp "%GFX%\Adafruit_GFX.cpp"

g++ -o simulateur.exe -DARDUINO=100 -Iarduino -Igxepd2 -I"%GFX%" %SOURCES% && simulateur.exe && start ecran.bmp
