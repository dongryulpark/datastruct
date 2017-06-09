#ifndef _SAVEMODE_H_
#define _SAVEMODE_H_

#include <Windows.h>
#include "console.h"
#include "doublylinkedlist.h"

void saveMode();
void printSaveMenu();
int scanSaveMenu();
void printSaveProcess();
void saveAtFile();
void loadFromFile();

#endif//_SAVEMODE_H_