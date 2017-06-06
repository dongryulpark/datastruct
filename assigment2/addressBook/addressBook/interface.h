#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <Windows.h>

#define midX 50
#define midY 20

void gotoxy(int x, int y);
void setCursorMiddle(int YOffset);
void printStringAtMiddle(char* String, int YOffset);
void printCyperight();
void printMenu();

#endif // !_INTERFACE_H_