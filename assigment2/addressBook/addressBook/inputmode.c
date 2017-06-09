#include "inputmode.h"

void inputMode() {
	while (1) {
		makeNewNode();
		printInputMenu();
		if (!scanInputMenu()) break;
		else continue;
	}
	system("cls");
}

void printInputMenu() {
	printStringAtMiddle("1 go to main menu", -1);
	printStringAtMiddle("2 continue       ", 0);
	setCursorAtMiddle(1);
}

void makeNewNode() {
	char* studentID, *name, *sex, *contact, *address;

	printStringAtMiddle("input your studantID", -4);
	setCursorAtMiddle(-3);
	studentID = getString();
	printStringAtMiddle("input your name", -2);
	setCursorAtMiddle(-1);
	name = getString();
	printStringAtMiddle("input your sex", 0);
	setCursorAtMiddle(1);
	sex = getString();
	printStringAtMiddle("input your phone number", 2);
	setCursorAtMiddle(3);
	contact = getString();
	printStringAtMiddle("input your address", 4);
	setCursorAtMiddle(5);
	address = getString();

	insertAtTail(studentID, name, sex, contact, address);
	system("cls");
}

int scanInputMenu() {
	int formValidatior;
	char buffer[100];

	while (1) {
		fgets(buffer, 100, stdin);
		formValidatior = strlen(buffer);
		if (formValidatior != 2) {
			printStringAtMiddle("wrong input you must input 1 ~ 2", 1);
			printStringAtMiddle("                                ", 2);
			setCursorAtMiddle(2);
			continue;
		}
		else if (buffer[0] > (2 + 48) || buffer[0] < (1 + 48)) {
			printStringAtMiddle("wrong input you must input 1 ~ 2", 1);
			printStringAtMiddle("                                ", 2);
			setCursorAtMiddle(2);
			continue;
		}
		else break;
	}
	system("cls");
	return buffer[0] - 49;
}