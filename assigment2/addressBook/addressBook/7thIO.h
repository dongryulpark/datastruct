#ifndef _7THIO_H_
#define _7THIO_H_

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

#define midX 50
#define midY 20

void printCyperight();
void printMenu();
int scanMenu();
char* getString();
void printSearchMenu();

void gotoxy(int x, int y);
void setCursorAtMiddle(int YOffset);
void printStringAtMiddle(char* String, int YOffset);
#endif//_7THIO_H_
