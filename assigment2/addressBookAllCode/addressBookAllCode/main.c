#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

typedef struct DoublyLinkedNode {
	char* studantID;   //2015161054
	char* name;
	char* sex;
	char* contact;
	char* address;
	struct DoublyLinkedNode* next;
	struct DoublyLinkedNode* prev;
} doublyLinkedNode;
typedef struct QueueNode {
	doublyLinkedNode* searchedNode;
	struct QueueNode* link;
} queueNode;
typedef struct FactorOfQueue {
	queueNode *front, *rear;
} factorOfQueue;

#define midX 50
#define midY 20

struct DoublyLinkedNode* getNewNode(char* studantID, char* name, char* sex, char* contact, char* address);
void insertAtHead(char* studantID, char* name, char* sex, char* contact, char* address);
void insertAtTail(char* studantID, char* name, char* sex, char* contact, char* address);

factorOfQueue* getNewQueue();
void getNewQueueNode(factorOfQueue* fQ, doublyLinkedNode* dataNode);


factorOfQueue* searchNodeByStudantId(char* studantId);
factorOfQueue* searchNodeByName(char* name);
factorOfQueue* searchNodeByAddress(char* address);

void loadFromFile();
void saveAtFile();

void gotoxy(int x, int y);
void setCursorAtMiddle(int YOffset);
void printStringAtMiddle(char* String, int YOffset);
void printCyperight();
void printMenu();
int scanMenu();


char* getString();
void printSearchMenu();

void inputMode();
//void deleteMode();
//void searchMode();
void printMode();

doublyLinkedNode* head;
const char path[30] = ".\\txt\\DB.bin";

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
			modifymode();*/
		/*else if (selectedMenu == 3)
			deleteMode();*/
		/*else if (selectedMenu == 4)
			searchMode();*/ 
		else if (selectedMenu == 5)
			printMode();
		/*else if (selectedMenu == 6)
			savemode();*/
		else if (selectedMenu == 7)
			break;
	}
	system("pause");
}

char* getString() {
	int stringLength, j;
	char temp[100];
	char* string;

	gets(temp);
	
	stringLength = strlen(temp);

	string = (char*)malloc(sizeof(char)*(stringLength + 1));
	
	for (j = 0; j <= stringLength; j++)
		string[j] = temp[j];
	string[stringLength + 1] = '\0';
	return string;
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
		printStringAtMiddle("file open error", 0);
		return;
	}

	while (temp != NULL) {
		fprintf(filePointer, "%s ", temp->studantID);
		fprintf(filePointer, "%s ", temp->name);
		fprintf(filePointer, "%s ", temp->sex);
		fprintf(filePointer, "%s ", temp->contact);
		fprintf(filePointer, "%s ", temp->address);
		fprintf(filePointer, "\n");
		temp = temp->next;
	}
}
struct DoublyLinkedNode* getNewNode(char* studantID, char* name, char* sex, char* contact, char* address) {
	doublyLinkedNode* newNode = (doublyLinkedNode*)malloc(sizeof(doublyLinkedNode));
	newNode->studantID = studantID;
	newNode->name = name;
	newNode->sex = sex;
	newNode->contact = contact;
	newNode->address = address;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
void insertAtHead(char* studantID, char* name, char* sex, char* contact, char* address) {
	doublyLinkedNode* newNode = getNewNode(studantID, name, sex, contact, address);
	if (head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}
void insertAtTail(char* studantID, char* name, char* sex, char* contact, char* address) {
	doublyLinkedNode* temp = head;
	doublyLinkedNode* newNode = getNewNode(studantID, name, sex, contact, address);
	if (head == NULL) {
		head = newNode;
		return;
	}
	while (temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}
factorOfQueue* getNewQueue() {
	factorOfQueue* fQ;
	fQ = (factorOfQueue*)malloc(sizeof(factorOfQueue));
	fQ->front = NULL;
	fQ->rear = NULL;
	return fQ;
}

void getNewQueueNode(factorOfQueue* fQ, doublyLinkedNode* dataNode) {
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
	newNode->searchedNode = dataNode;
	newNode->link = NULL;
	if (fQ->front == NULL) {
		fQ->front = newNode;
		fQ->rear = newNode;
	}
	else {
		fQ->rear->link = newNode;
		fQ->rear = newNode;
	}
}


void gotoxy(int x, int y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void printStringAtMiddle(char* String, int YOffset) {
	int XOffset = (strlen(String) / 2);

	gotoxy(midX - XOffset, midY + YOffset);
	puts(String);
}

void setCursorAtMiddle(int YOffset) {
	gotoxy(midX, midY + YOffset);
}

void printCyperight() {
	printStringAtMiddle("B308 AddressBook Program", 0);
	printStringAtMiddle("Copyright(c) 7Á¶", 1);
	setCursorAtMiddle(2);
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
	printStringAtMiddle("7 end   ", 6);
	setCursorAtMiddle(7);
}


int scanMenu() {
	int formValidatior;
	char buffer[100];

	while (1) {
		gets(buffer);
		formValidatior = strlen(buffer);
		if (formValidatior != 1) {
			printStringAtMiddle("wrong input you must input 1 ~ 6", 6);
			printStringAtMiddle("                                ", 7);
			setCursorAtMiddle(7);
			continue;
		}
		else if (buffer[0] > (7 + 48) || buffer[0] < (1 + 48)) {
			printStringAtMiddle("wrong input you must input 1 ~ 6", 6);
			printStringAtMiddle("                                ", 7);
			setCursorAtMiddle(7);
			continue;
		}
		else break;
	}
	system("cls");
	return buffer[0] - 48;
}
void printSearchMenu() {
	printStringAtMiddle("1 studantID ", 0);
	printStringAtMiddle("2 name      ", 1);
	printStringAtMiddle("3 sex       ", 2);
	printStringAtMiddle("4 contact   ", 3);
	printStringAtMiddle("5 address   ", 4);
	printStringAtMiddle("6 end   ", 6);
	setCursorAtMiddle(5);
}
int scanSearchMenu() {
	int formValidatior;
	char buffer[100];

	while (1) {
		gets(buffer);
		formValidatior = strlen(buffer);
		if (formValidatior != 1) {
			printStringAtMiddle("wrong input you must input 1 ~ 6", 6);
			printStringAtMiddle("                                ", 7);
			setCursorAtMiddle(7);
			continue;
		}
		else if (buffer[0] > (6 + 48) || buffer[0] < (1 + 48)) {
			printStringAtMiddle("wrong input you must input 1 ~ 6", 6);
			printStringAtMiddle("                                ", 7);
			setCursorAtMiddle(7);
			continue;
		}
		else break;
	}
	system("cls");
	return buffer[0] - 48;
}
void inputMode() {
	char* studentID, *name, *sex, *contact, *address;

	printStringAtMiddle("input your studantID", 0);
	setCursorAtMiddle(1);
	studentID = getString();
	printStringAtMiddle("input your name", 2);
	setCursorAtMiddle(3);
	name = getString();
	printStringAtMiddle("input your sex", 4);
	setCursorAtMiddle(5);
	sex = getString();
	printStringAtMiddle("input your phone number", 6);
	setCursorAtMiddle(7);
	contact = getString();
	printStringAtMiddle("input your address", 8);
	setCursorAtMiddle(9);
	address = getString();

	insertAtHead(studentID, name, sex, contact, address);
	system("cls");
}
/*void deleteMode() {

}*/
/*void searchMode() {
	int selectedMenu;
	printSearchMenu();
	selectedMenu = scanMenu();
	
	if (selectedMenu == 1)
		
	else if (selectedMenu == 2)
		
	else if (selectedMenu == 3)
		
	else if (selectedMenu == 4)
		
	else if (selectedMenu == 5)
		
	else if (selectedMenu == 6) return;

}*/
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
		if (getch() == 27) {
			system("cls");
			break;
		}
	}
}