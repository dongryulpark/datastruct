#ifndef _DOUBLYLINKEDLIST_H_
#define _DOUBLYLINKEDLIST_H_

#include <stdio.h>

typedef struct DoublyLinkedNode {
	char* studantID;   //2015161054
	char* name;
	char* sex;
	char* contact;
	char* address;
	struct DoublyLinkedNode* next;
	struct DoublyLinkedNode* prev;
} doublyLinkedNode;

doublyLinkedNode* head;

struct DoublyLinkedNode* getNewNode(char* studantID, char* name, char* sex, char* contact, char* address);
void insertAtHead(char* studantID, char* name, char* sex, char* contact, char* address);
void insertAtTail(char* studantID, char* name, char* sex, char* contact, char* address);
void forwardPrint();
void reversePrint();


#endif // !_DOUBLYLINKEDLIST_H_

