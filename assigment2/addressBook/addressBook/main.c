#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublylinkedlist.h"
#include "queue.h"
#include "console.h"
#include "util.h"
#include "inputmode.h"
#include "savemode.h"
#include "printmode.h"
#include "searchmode.h"

/*
todo
modify구현

file 처리 
	save to file 위치 지정
	load from 구현 
sort 구현 dksgo dksgo dksgo
*/

void printMenu();
int scanMenu();

//todo modify각함수 구현
void modifyMode();
void printModifyMenu();
int scanModifyMenu();

void modifyByStudantId();
void modifyByName();
void modifyBySex();
void modifyByContact();
void modifyByAddress();

int main() {
	int selectedMenu;
	head = NULL; // empty list. set head as NULL.
	system("mode con:cols=100 lines=40");

	printCyperight();
	while (1) {
		printMenu();
		selectedMenu = scanMenu();

		if (selectedMenu == 1)
			inputMode();
		else if (selectedMenu == 2)
			modifyMode();
		/*else if (selectedMenu == 3)
			deleteMode();*/
		else if (selectedMenu == 4)
			searchMode();
		else if (selectedMenu == 5)
			printMode();
		else if (selectedMenu == 6)
			saveMode();
		else if (selectedMenu == 7)
			break;
	}
	system("pause");
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

void modifyMode() {
	while (1) {
		printModifyMenu();
		if (!scanModifyMenu()) break;
		else continue;
	}
	system("cls");
}

void printModifyMenu() {
	printStringAtMiddle("1 studantID  ", -3);
	printStringAtMiddle("2 name       ", -2);
	printStringAtMiddle("3 sex        ", -1);
	printStringAtMiddle("4 contact    ", 0);
	printStringAtMiddle("5 address    ", 1);
	printStringAtMiddle("6 end        ", 2);
	setCursorAtMiddle(3);
}

int scanModifyMenu() {
	int formValidatior;
	char buffer[100];

	while (1) {
		fgets(buffer, 100, stdin);
		formValidatior = strlen(buffer);
		if (formValidatior != 2) {
			printStringAtMiddle("wrong input you must input 1 ~ 6", 3);
			printStringAtMiddle("                                ", 4);
			setCursorAtMiddle(4);
			continue;
		}
		else if (buffer[0] > (6 + 48) || buffer[0] < (1 + 48)) {
			printStringAtMiddle("wrong input you must input 1 ~ 6", 3);
			printStringAtMiddle("                                ", 4);
			setCursorAtMiddle(4);
			continue;
		}
		else break;
	}
	system("cls");
	return buffer[0] - (48 + 6);
}

void modifyByStudantId() {
	factorOfQueue* fQ = NULL;
	queueNode* temp = NULL;
	char* inputStudantId = NULL;
	int queueNum = 0, offsetY = 0;
	
	printStringAtMiddle("input modify string", 0);
	setCursorAtMiddle(1);
	inputStudantId = getString();
	fQ = searchByStudantId(inputStudantId);

	if (fQ == NULL || fQ->front == NULL){
		searchDataIsEmpty(fQ);
		return;
	}
	
	temp = fQ->front;
	for (queueNum = 0; temp; queueNum++) temp = temp-> link;
	queueNum = queueNum - 1;
	
	if (queueNum != 0) 
		offsetY = printQueue(fQ);

	
	if (strlen(inputStudantId) != 10) {
		
	}
}

void modifyByName() {

}

void modifyBySex() {

}

void modifyByContact() {

}
void modifyByAddress() {

}
