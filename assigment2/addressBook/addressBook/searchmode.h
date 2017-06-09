#ifndef _SEACHMODE_H_
#define _SEARCHMODE_H_

#include "queue.h"
#include "util.h"
#include "console.h"
#include <conio.h>
#include <Windows.h>


void searchMode();
void printSearchMenu();
int scanSearchMenu();
void searchByEachElement(int menuSelect);
void searchDataIsEmpty(factorOfQueue* fQ);
factorOfQueue* searchByStudantId(char * searchString);
factorOfQueue* searchByName(char * searchString);
factorOfQueue* searchBySex(char * searchString);
factorOfQueue* searchByContact(char * searchString);
factorOfQueue* searchByAddress(char * searchString);
factorOfQueue* searchByAllcontant(char * searchString);

#endif // !_SEACHMODE_H_

