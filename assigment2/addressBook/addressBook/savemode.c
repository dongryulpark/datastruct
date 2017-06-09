#include "savemode.h"

const char path[30] = ".\\bin\\DB.txt";

void saveMode() {
	printSaveMenu();
	if (!scanSaveMenu()) {
		saveAtFile();
		printSaveProcess();
	}
	system("cls");
}

void printSaveMenu() {
	printStringAtMiddle("1 save", -1);
	printStringAtMiddle("2 exit", 0);
	setCursorAtMiddle(1);
}

int scanSaveMenu() {
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

void printSaveProcess() {
	printStringAtMiddle("progress save", 0);
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
}

void saveAtFile() {
	FILE * filePointer;
	doublyLinkedNode* temp = head;

	if (fopen_s(&filePointer, path, "w") != 0) {
		printStringAtMiddle("there is no file in dir", 0);
		return;
	}

	while (temp != NULL) {
		fprintf(filePointer, "%s ", temp->studantID);
		fprintf(filePointer, "%s ", temp->name);
		fprintf(filePointer, "%s ", temp->sex);
		fprintf(filePointer, "%s ", temp->contact);
		fprintf(filePointer, "%s", temp->address);
		fprintf(filePointer, "\n");
		temp = temp->next;
	}

}

void loadFromFile() {
	FILE *filePointer;

	if (fopen_s(&filePointer, path, "r") != 0) {
		printStringAtMiddle("there is no file in dir", 0);
		return;
	}

	//fgets(temp);
}
