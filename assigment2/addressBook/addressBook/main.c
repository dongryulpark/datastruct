#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define midX 30
#define midY 30

// todo 
// doubly linked list studant address book make
// bin file과 real time으로 통신하면서 DB를 구현한다.
// 1) 입력
//	esc로 중간 탈주 
// 2) 수정
//	검색 후 수정
//	esc로 중간 탈주 
// 3) 삭제
//	검색 후 삭제
//	esc로 중간 탈주 
// 4) search V
// queue를 이용해 구현 완료
// 5) 출력
//	콘솔창의 크기를 정하자
//	넘어가면 방향키를 입력받아 넘어가면서 보게 하고 esc로 나가게 한다.
// 6) 파일저장 V
//	realtime으로 자동적으로 저장이 된다.

const char path[30] = ".\\txt\\DB.bin";

typedef struct DoublyLinkedNode {
	long studantID;   //2015161054
	char* name;
	char* address;
	struct DoublyLinkedNode* next;
	struct DoublyLinkedNode* prev;
} doublyLinkedNode;

typedef struct QueueNode {
	doublyLinkedNode* dataNode;
	struct QueueNode* link;
} queueNode;

typedef struct FactorOfQueue{
	queueNode *front, *rear;
} factorOfQueue;

doublyLinkedNode* head; // global variable - pointer to head node.

void gotoxy(int x, int y);

struct DoublyLinkedNode* getNewNode(int studantID, char * name, char * address);
void insertAtHead(int studantID, char * name, char * address);
// todo insertAtMiddle
void insertAtTail(int studantID, char * name, char * address);
void forwardPrint();
void reversePrint();

factorOfQueue* getNewQueue();
void getNewQueueNode(factorOfQueue* fQ, doublyLinkedNode* dataNode);

queueNode* searchNodeByStudantId(long studantId);
queueNode* searchNodeByName(char* name);
queueNode* searchNodeByAddress(char* address);

void loadFromFile() {}
void saveAtFile() {}

void gotoxy(int x, int y);
void printStringAtMiddle(char* String, int YOffset);

int main() {
	head = NULL; // empty list. set head as NULL.
}

/*doublyLinkedList functions
* use github code
*/

//Creates a new Node and returns pointer to it. 
struct DoublyLinkedNode* getNewNode(int studantID, char * name, char * address) {
	doublyLinkedNode* newNode = (doublyLinkedNode*)malloc(sizeof(doublyLinkedNode));
	newNode->studantID = studantID;
	newNode->name = name;
	newNode->address = address;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//Inserts a Node at head of doubly linked list
void insertAtHead(int studantID, char * name, char * address) {
	doublyLinkedNode* newNode = getNewNode(studantID, name, address);
	if (head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

//Inserts a Node at tail of Doubly linked list
void insertAtTail(int studantID, char * name, char * address) {
	doublyLinkedNode* temp = head;
	doublyLinkedNode* newNode = getNewNode(studantID, name, address);
	if (head == NULL) {
		head = newNode;
		return;
	}
	while (temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

//Prints all the elements in linked list in forward traversal order
void forwardPrint() {
	struct DoublyLinkedNode* temp = head;
	printf("Forward: \n");
	while (temp != NULL) {
		printf("%8ld ", temp->studantID);
		printf("%s ", temp->name);
		printf("%s ", temp->address);
		printf("\n");
		temp = temp->next;
	}
	printf("\n");
}

//Prints all elements in linked list in reverse traversal order. 
void reversePrint() {
	struct DoublyLinkedNode* temp = head;
	if (temp == NULL) return; // empty list, exit
	while (temp->next != NULL) {// Going to last Node
		temp = temp->next;
	}
	// Traversing backward using prev pointer
	printf("Reverse: \n");
	while (temp != NULL) {
		printf("%8ld ", temp->studantID);
		printf("%s ", temp->name);
		printf("%s ", temp->address);
		printf("\n");
		temp = temp->prev;
	}
	printf("\n");
}

/*queue functions
* create by dongryulpark
*/

factorOfQueue* getNewQueue() {
	factorOfQueue* fQ; 
	fQ = (factorOfQueue*)malloc(sizeof(factorOfQueue));
	fQ->front = NULL;
	fQ->rear = NULL;
	return fQ;
}

void getNewQueueNode(factorOfQueue* fQ, doublyLinkedNode* dataNode) {
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
	newNode->dataNode = dataNode;
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

/*search functions
* create by dongryulpark
*/

factorOfQueue* searchNodeByStudantId(long studantId) {
	doublyLinkedNode* temp = head;
	factorOfQueue* fQ = getNewQueue();

	while (temp->next != NULL) {
		if (studantId == temp->studantID) 
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
	// todo load code작성

}

void saveAtFile() {
	FILE * filePointer;
	doublyLinkedNode* temp = head;

	if (fopen_s(&filePointer, path, "wb") != 0) {
		printStringAtMiddle("there is no file in dir", 0);
		return;
	}
	
	while (temp != NULL) {
		fprintf(filePointer, "%8ld ", temp->studantID);
		fprintf(filePointer, "%s ", temp->name);
		fprintf(filePointer, "%s ", temp->address);
		fprintf(filePointer, "\n");
		temp = temp->next;
	}
}

/*interface functions
* create by dongRyulPark
*/

void gotoxy(int x, int y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void printStringAtMiddle(char* String,int YOffset) {
	int XOffset = (strlen(String) / 2);

	gotoxy(midX - XOffset, midY - YOffset);
	puts(String);
}

