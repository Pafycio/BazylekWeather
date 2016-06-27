#pragma once
#include "modul.h"

typedef struct controller
{
    int modulsCount;
    Modul **moduls;
    char *modulsInfo;
} Controller;

Controller *makeController();
int getMaxModulsCount(Controller *c);
char *getModulsPacketInfo();
void addModulToController(Modul *m, Controller *c);
void emitModulsUpdateRequest(Controller *c);
void updateModulsInfo(Controller *c);
void freeController(Controller *c);
