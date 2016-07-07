#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "modul.h"

#define DATA_SIZE 100

Modul *makeModul(unsigned int pin, enum ModulType type)
{
    Modul *m = (Modul *)malloc(sizeof(Modul));
    m->data = (char *)malloc(sizeof(char) * DATA_SIZE);
    if (m && type)
    {
        m->pin = pin;
        m->type = type;
    }
    return m;
}

unsigned int getPin(Modul *m)
{
    if (m != NULL)
    {
        return m->pin;
    }
    return 0;
}

enum ModulType getType(Modul *m)
{
    if (m != NULL)
    {
        return m->type;
    }
    return none;
}

char *getData(Modul *m)
{
    return m->data; // m->value;
}

void setPin(Modul *m, unsigned int pin)
{
    m->pin = pin;
}
void setType(Modul *m, enum ModulType type)
{
    m->type = type;
}

void setData(Modul *m, char *data)
{
    free(m->data);
    m->data = (char *)malloc(sizeof(data));
    strcpy(m->data, data);
}

void update(Modul *m)
{
    // m->setData(DIGITAL_READ(m->getPin()))
    setData(m, "TEST");
    return;
}

void freeModul(Modul *m)
{
    free(m);
    m = NULL;
}
