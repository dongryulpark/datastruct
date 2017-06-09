#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

#define midX 50
#define midY 20

void gotoxy(int x, int y);
void setCursorAtMiddle(int YOffset);
void printStringAtMiddle(char* String, int YOffset);
void printCyperight();

#endif//_CONSOLE_H_


