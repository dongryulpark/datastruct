#include "doublylinkedlist.h"

//Creates a new Node and returns pointer to it. 
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

//Inserts a Node at head of doubly linked list
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

//Inserts a Node at tail of Doubly linked list
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
