#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublylinkedlist.h"
#include "queue.h"
#include "7thIO.h"

const char path[30] = ".\\bin\\DB.txt";

/*
sort 구현
search 구현
file 처리  
	load from 구현
*/

void makeNewNode();
void printInputMenu();
int scanInputMenu();

void printSaveMenu();
int scanSaveMenu();
void printSaveProcess();

void printSearchMenu();
int scanSearchMenu();

// search 처리
factorOfQueue* searchByStudantId();
factorOfQueue* searchByName();
factorOfQueue* searchBySex();
factorOfQueue* searchByContact();
factorOfQueue* searchByAddress();

void saveAtFile();
// todo file 처리
void loadFromFile();

void inputMode();
void printMode();
void saveMode();
void searchMode();
//void modifyMode();

//todo modify각함수 구현
//void modifyById();

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
		/*else if (selectedMenu == 2)
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

/*file functions
*create by dongryulpark
*/

void loadFromFile() {
	FILE *filePointer;

	if (fopen_s(&filePointer, path, "r") != 0) {
		printStringAtMiddle("there is no file in dir", 0);
		return;
	}
	
	//fgets(temp);
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

void printMode() {
	struct DoublyLinkedNode* temp = head;
	int offsetY = 0;

	printf("Forward: \n");
	while (temp != NULL) {
		//studantID, name,sex,contact, address
		printf("%s ", temp->studantID);
		printf("%s ", temp->name);
		printf("%s ", temp->sex);
		printf("%s ", temp->contact);
		printf("%s ", temp->address);
		printf("\n");
		temp = temp->next;
		offsetY++;
	}
	while (1) {
		printStringAtMiddle("type ESC to escape", offsetY - 18);
		setCursorAtMiddle(offsetY - 17);
		if (_getch() == 27) {
			system("cls");
			break;
		}
	}
}

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

	insertAtHead(studentID, name, sex, contact, address);
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

//
//void modifyMode() {
//
//
//}
//
//
////search를 구현해야함
//
//void modifyById() {
//	int i, p = 1;
//	int temp = head;
//	//char NewID[MAX_HLEN];
//
//	printf("Before ID : %s\n", dataNode->id);
//	printf("New    ID : ");
//	scanf("%s", NewID, MAX_HLEN);
//
//	while (1) {
//		p = 1;
//		if (strlen(NewID) != 10){ //학번길이10글자가 안되거나 넘는경우
//			printf("학번길이를 잘못입력하셨습니다\n");
//			p = 0;
//		}
//		else {         //학번길이 10글자가 맞는 경우
//			for (i = 0; i < 10; i++){
//				if (NewID[i] < '0' || NewID[i] > '9') {
//					printf("학번에 숫자가 아닌 문자가 입력되었습니다\n");
//					p = 0;
//					break;
//				}
//			}
//		}
//		if (p) {
//			strcpy(dataNode->id, NewID);
//			return;
//		}
//	}
//}

factorOfQueue* searchByStudantId() {
	doublyLinkedNode* temp = head;
	factorOfQueue* fQ = getNewQueue();
	char* studantId;

	printStringAtMiddle("input seacr string", 0);
	studantId = getString();

	while (temp != NULL) {
		if (strstr(temp->studantID,studantId))
			getNewQueueNode(fQ, temp);
		temp = temp->next;
	}

	return fQ;
}
factorOfQueue* searchByName() {
	doublyLinkedNode* temp = head;
	factorOfQueue* fQ = getNewQueue();
	char* name;

	printStringAtMiddle("input seacr string", 0);
	name = getString();

	while (temp != NULL) {
		if (strstr(temp->name, name))
			getNewQueueNode(fQ, temp);
		temp = temp->next;
	}

	return fQ;
}
factorOfQueue* searchBySex() {
	doublyLinkedNode* temp = head;
	factorOfQueue* fQ = getNewQueue();
	char* sex;

	printStringAtMiddle("input seacr string", 0);
	sex = getString();

	while (temp != NULL) {
		if (strstr(temp->name, sex))
			getNewQueueNode(fQ, temp);
		temp = temp->next;
	}

	return fQ;
}
factorOfQueue* searchByContact() {
	doublyLinkedNode* temp = head;
	factorOfQueue* fQ = getNewQueue();
	char* contact;

	printStringAtMiddle("input seacr string", 0);
	contact = getString();

	while (temp != NULL) {
		if (strstr(temp->name, contact))
			getNewQueueNode(fQ, temp);
		temp = temp->next;
	}

	return fQ;
}
factorOfQueue* searchByAddress() {
	doublyLinkedNode* temp = head;
	factorOfQueue* fQ = getNewQueue();
	char* address;

	printStringAtMiddle("input seacr string", 0);
	address = getString();

	while (temp != NULL) {
		if (strstr(temp->name, address))
			getNewQueueNode(fQ, temp);
		temp = temp->next;
	}

	return fQ;
}

void printSearchMenu() {
	printStringAtMiddle("1 studantID", -2);
	printStringAtMiddle("2 name     ", -1);
	printStringAtMiddle("3 sex      ", 0);
	printStringAtMiddle("4 contact  ", 1);
	printStringAtMiddle("5 address  ", 2);
	setCursorAtMiddle(3);
}

int scanSearchMenu() {
	int formValidatior;
	char buffer[100];

	while (1) {
		fgets(buffer, 100, stdin);
		formValidatior = strlen(buffer);
		if (formValidatior != 2) {
			printStringAtMiddle("wrong input you must input 1 ~ 2", 3);
			printStringAtMiddle("                                ", 4);
			setCursorAtMiddle(4);
			continue;
		}
		else if (buffer[0] > (5 + 48) || buffer[0] < (1 + 48)) {
			printStringAtMiddle("wrong input you must input 1 ~ 2", 3);
			printStringAtMiddle("                                ", 4);
			setCursorAtMiddle(4);
			continue;
		}
		else break;
	}
	system("cls");
	return buffer[0] - 49;
}

void searchMode() {
	
}