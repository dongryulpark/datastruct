#include "7thIO.h"

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

void printMenu() {
	printStringAtMiddle("1 input ", -3);
	printStringAtMiddle("2 modify", -2);
	printStringAtMiddle("3 delete", -1);
	printStringAtMiddle("4 search", 0);
	printStringAtMiddle("5 print ", 1);
	printStringAtMiddle("6 save  ", 2);
	printStringAtMiddle("7 end   ", 3);
	setCursorAtMiddle(4);
}

char* getString() {
	int stringLength, j;
	char temp[100];
	char* string;

	fgets(temp, 100, stdin);

	stringLength = strlen(temp);

	string = (char*)malloc(sizeof(char)*(stringLength + 1));

	for (j = 0; j < stringLength - 1; j++)
		string[j] = temp[j];
	string[stringLength -1] = '\0';
	return string;
}

int scanMenu() {
	int formValidatior;
	char buffer[100];

	while (1) {
		fgets(buffer, 100, stdin);
		formValidatior = strlen(buffer);
		if (formValidatior != 2) {
			printStringAtMiddle("wrong input you must input 1 ~ 6", 4);
			printStringAtMiddle("                                ", 5);
			setCursorAtMiddle(5);
			continue;
		}
		else if (buffer[0] > (7 + 48) || buffer[0] < (1 + 48)) {
			printStringAtMiddle("wrong input you must input 1 ~ 6", 4);
			printStringAtMiddle("                                ", 5);
			setCursorAtMiddle(5);
			continue;
		}
		else break;
	}
	system("cls");
	return buffer[0] - 48;
}

void printSearchMenu() {
	printStringAtMiddle("1 studantID ", -3);
	printStringAtMiddle("2 name      ", -2);
	printStringAtMiddle("3 sex       ", -1);
	printStringAtMiddle("4 contact   ", 0);
	printStringAtMiddle("5 address   ", 1);
	printStringAtMiddle("6 end       ", 2);
	setCursorAtMiddle(3);
}
