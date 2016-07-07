#include <stdlib.h>
#include <stdio.h>
#include "modul_controller.h"

#define MODUL_COUNT 10

Controller *makeController()
{
    Controller *c = malloc(sizeof(Controller *));
    if (c)
    {
        c->modulsCount = 0;
        c->moduls = malloc(sizeof(Modul *) * MODUL_COUNT);
        for (int i = 0; i < MODUL_COUNT; i++)
            c->moduls[i] = NULL;
        c->modulsInfo = (char *)malloc(sizeof(char *) * 50 * MODUL_COUNT);
    }
    return c;
}

int getMaxModulsCount(Controller *c)
{
    return MODUL_COUNT;
}

void addModulToController(Modul *m, Controller *c)
{
    if (m && c)
    {
        if (getMaxModulsCount(c) < c->modulsCount)
            printf("OVERFLOW\n");

        c->moduls[c->modulsCount++] = m;
    }
}

void emitModulsUpdateRequest(Controller *c)
{
    if (c)
    {
        for (int i = 0; i < c->modulsCount; i++)
        {
            update(c->moduls[i]);
        }
    }
}

void updateModulsInfo(Controller *c)
{
    if (c)
    {
        for (int i = 0; i < c->modulsCount; i++)
        {
            update(c->moduls[i]);
        }
    }
}

void freeController(Controller *c)
{
    if (c)
    {
        for (int i = 0; i < c->modulsCount; i++)
        {
            free(c->moduls[i]);
        }
        free(c->moduls);
        free(c->modulsInfo);
        free(c);
        c = NULL;
    }
}
