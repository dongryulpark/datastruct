#include "searchmode.h"

void searchMode() {
	int menuSelect = 0;
	while (1) {
		printSearchMenu();
		menuSelect = scanSearchMenu();
		if (!menuSelect) break;
		else searchByEachElement(menuSelect + 7);
	}
	system("cls");
}

void printSearchMenu() {
	printStringAtMiddle("1 studantID  ", -3);
	printStringAtMiddle("2 name       ", -2);
	printStringAtMiddle("3 sex        ", -1);
	printStringAtMiddle("4 contact    ", 0);
	printStringAtMiddle("5 address    ", 1);
	printStringAtMiddle("6 all contant", 2);
	printStringAtMiddle("7 end        ", 3);
	setCursorAtMiddle(4);
}

int scanSearchMenu() {
	int formValidatior;
	char buffer[100];

	while (1) {
		fgets(buffer, 100, stdin);
		formValidatior = strlen(buffer);
		if (formValidatior != 2) {
			printStringAtMiddle("wrong input you must input 1 ~ 7", 4);
			printStringAtMiddle("                                ", 5);
			setCursorAtMiddle(5);
			continue;
		}
		else if (buffer[0] > (7 + 48) || buffer[0] < (1 + 48)) {
			printStringAtMiddle("wrong input you must input 1 ~ 7", 4);
			printStringAtMiddle("                                ", 5);
			setCursorAtMiddle(5);
			continue;
		}
		else break;
	}
	system("cls");
	return buffer[0] - (48 + 7);
}

void searchByEachElement(int menuSelect) {
	factorOfQueue* fQ = NULL;
	int offsetY = 0;
	char * searchString;
	if (menuSelect == 1) {
		printStringAtMiddle("input seacrh string", 0);
		setCursorAtMiddle(1);
		searchString = getString();
		fQ = searchByStudantId(searchString);
	}
	else if (menuSelect == 2) {
		printStringAtMiddle("input seacrh string", 0);
		setCursorAtMiddle(1);
		searchString = getString();
		fQ = searchByName(searchString);
	}
	else if (menuSelect == 3) {
		printStringAtMiddle("input seacrh string", 0);
		setCursorAtMiddle(1);
		searchString = getString();
		fQ = searchBySex(searchString);
	}
	else if (menuSelect == 4) {
		printStringAtMiddle("input seacrh string", 0);
		setCursorAtMiddle(1);
		searchString = getString();
		fQ = searchByContact(searchString);
	}
	else if (menuSelect == 5) {
		printStringAtMiddle("input seacrh string", 0);
		setCursorAtMiddle(1);
		searchString = getString();
		fQ = searchByAddress(searchString);
	}
	else if (menuSelect == 6) {
		printStringAtMiddle("input seacrh string", 0);
		setCursorAtMiddle(1);
		searchString = getString();
		fQ = searchByAllcontant(searchString);
	}

	if (fQ == NULL || fQ->front == NULL) {
		searchDataIsEmpty(fQ);
		return;
	}
	else {
		offsetY = printQueue(fQ);
		escEscape(offsetY);
		free(fQ);
		system("cls");
	}
}

void searchDataIsEmpty(factorOfQueue* fQ) {
	while (1) {
		printStringAtMiddle("no search data", -1);
		printStringAtMiddle("type ESC to escape", 0);
		setCursorAtMiddle(1);
		if (_getch() == 27) {
			system("cls");
			break;
		}
	}
	free(fQ);
}


factorOfQueue* searchByStudantId(char * searchString) {
	doublyLinkedNode* temp = head;
	factorOfQueue* fQ = getNewQueue();
	
	while (temp != NULL) {
		if (strstr(temp->studantID, searchString))
			getNewQueueNode(fQ, temp);
		temp = temp->next;
	}

	system("cls");

	return fQ;
}

factorOfQueue* searchByName(char * searchString) {
	doublyLinkedNode* temp = head;
	factorOfQueue* fQ = getNewQueue();

	while (temp != NULL) {
		if (strstr(temp->name, searchString))
			getNewQueueNode(fQ, temp);
		temp = temp->next;
	}

	system("cls");

	return fQ;
}

factorOfQueue* searchBySex(char * searchString) {
	doublyLinkedNode* temp = head;
	factorOfQueue* fQ = getNewQueue();
	
	while (temp != NULL) {
		if (strstr(temp->sex, searchString))
			getNewQueueNode(fQ, temp);
		temp = temp->next;
	}

	system("cls");

	return fQ;
}

factorOfQueue* searchByContact(char * searchString) {
	doublyLinkedNode* temp = head;
	factorOfQueue* fQ = getNewQueue();
	
	while (temp != NULL) {
		if (strstr(temp->contact, searchString))
			getNewQueueNode(fQ, temp);
		temp = temp->next;
	}

	system("cls");

	return fQ;
}

factorOfQueue* searchByAddress(char * searchString) {
	doublyLinkedNode* temp = head;
	factorOfQueue* fQ = getNewQueue();
	
	while (temp != NULL) {
		if (strstr(temp->address, searchString))
			getNewQueueNode(fQ, temp);
		temp = temp->next;
	}

	system("cls");

	return fQ;
}

factorOfQueue* searchByAllcontant(char * searchString) {
	doublyLinkedNode* temp = head;
	factorOfQueue* fQ = getNewQueue();

	while (temp != NULL) {
		if (strstr(temp->studantID, searchString) || strstr(temp->name, searchString) ||
			strstr(temp->sex, searchString) || strstr(temp->contact, searchString) ||
			strstr(temp->address, searchString)) {
			getNewQueueNode(fQ, temp);
		}
		temp = temp->next;
	}

	system("cls");

	return fQ;
}
