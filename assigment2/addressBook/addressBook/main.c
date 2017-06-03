#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "doublylinkedlist.h"
#include "queue.h"

const char path[30] = ".\\txt\\DB.bin";

void getString(char* string);
factorOfQueue* searchNodeByStudantId(char* studantId);
factorOfQueue* searchNodeByName(char* name);
factorOfQueue* searchNodeByAddress(char* address);

void loadFromFile();
void saveAtFile();

int main() {
	head = NULL; // empty list. set head as NULL.
	system("mode con:cols=100 lines=40");
	printCyperight();
	printMenu();
	system("pause");
}

void getString(char* string) {
	int i, j;
	char temp[100];
	gets(temp);
	for (i = 0; temp[i] != '\0'; i++);
	string = (char*)malloc(sizeof(char)*(i + 1));
	for (j = 0; j <= i; j++)
		string[j] = temp[j];
}

/*search functions
* create by dongryulpark
*/
factorOfQueue* searchNodeByStudantId(char* studantId) {
	doublyLinkedNode* temp = head;
	factorOfQueue* fQ = getNewQueue();

	while (temp->next != NULL) {
		if (!strcmp(studantId, temp->studantID))
			getNewQueueNode(fQ, temp);
		temp = temp->next;
	}

	return fQ;
}

factorOfQueue* searchNodeByName(char* name) {
	doublyLinkedNode* temp = head;
	factorOfQueue* fQ = getNewQueue();

	while (temp->next != NULL) {
		if (!strcmp(name, temp->name))
			getNewQueueNode(fQ, temp);
		temp = temp->next;
	}

	return fQ;
}

factorOfQueue* searchNodeByAddress(char* address) {
	doublyLinkedNode* temp = head;
	factorOfQueue* fQ = getNewQueue();

	while (temp->next != NULL) {
		if (!strcmp(address, temp->address))
			getNewQueueNode(fQ, temp);
		temp = temp->next;
	}
	return fQ;
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
	// todo load codeÀÛ¼º

}

void saveAtFile() {
	FILE * filePointer;
	doublyLinkedNode* temp = head;

	if (fopen_s(&filePointer, path, "wb") != 0) {
		printStringAtMiddle("there is no file in dir", 0);
		return;
	}
	
	while (temp != NULL) {
		fprintf(filePointer, "%s ", temp->studantID);
		fprintf(filePointer, "%s ", temp->name);
		fprintf(filePointer, "%s ", temp->address);
		fprintf(filePointer, "\n");
		temp = temp->next;
	}
}

