#ifndef _NV_COLOR_MANAGER_H
#define _NV_COLOR_MANAGER_H

#include<ncurses.h>
#include<stdlib.h>
#include<cgenerics/CGAppState.h>

typedef struct {
    int nextPair;
} nvColorManager;

nvColorManager *nvColorManager__getInstance();
void nvColorManager_delete(nvColorManager * this);
int nvColorManager_createColor(nvColorManager* this, short fg, short bg);

#endif
