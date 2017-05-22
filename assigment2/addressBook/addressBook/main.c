
//doubly linkedlist address book
//i use github code 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
	/*Driver code to test the implementation*/
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
		printf("%d ", temp->studantID);
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
		printf("%d ", temp->studantID);
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

