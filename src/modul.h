#pragma once

enum ModulType
{
    none,
    temp,
    hPa,
    PM25,
    PM10
};

typedef struct modul
{
    char* data;
    unsigned int pin;
    enum ModulType type;
} Modul;

Modul *makeModul(unsigned int pin, enum ModulType type);
unsigned int getPin(Modul *m);
enum ModulType getType(Modul *m);
char *getData(Modul *m);
void setPin(Modul *m, unsigned int pin);
void setType(Modul *m, enum ModulType type);
void setData(Modul *m, char *data);
void update(Modul *m);
void freeModul(Modul *m);
