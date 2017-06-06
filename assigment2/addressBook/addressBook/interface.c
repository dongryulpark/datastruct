#include "interface.h"

void gotoxy(int x, int y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void printStringAtMiddle(char* String, int YOffset) {
	int XOffset = (strlen(String) / 2);

	gotoxy(midX - XOffset, midY + YOffset);
	puts(String);
}

void setCursorMiddle(int YOffset) {
	gotoxy(midX, midY + YOffset);
}

void printCyperight() {
	printStringAtMiddle("B308 AddressBook Program", 0);
	printStringAtMiddle("Copyright(c) 7Á¶", 1);
	getch();
	system("cls");
}

void printMenu() {
	printStringAtMiddle("1 input ", 0);
	printStringAtMiddle("2 modify", 1);
	printStringAtMiddle("3 delete", 2);
	printStringAtMiddle("4 search", 3);
	printStringAtMiddle("5 print ", 4);
	printStringAtMiddle("6 save  ", 5);
	setCursorMiddle(6);
}

