#include "console.h"

void gotoxy(int x, int y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void printStringAtMiddle(char* String, int YOffset) {
	int XOffset = (strlen(String) / 2);

	gotoxy(midX - XOffset, midY + YOffset);
	printf("%s",String);
}

void setCursorAtMiddle(int YOffset) {
	gotoxy(midX, midY + YOffset);
}

void printCyperight() {
	printStringAtMiddle("B308 AddressBook Program", -1);
	printStringAtMiddle("Copyright(c) 7Á¶", 0);
	setCursorAtMiddle(1);
	_getch();
	system("cls");
}
