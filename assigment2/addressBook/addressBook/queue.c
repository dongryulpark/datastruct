#include "queue.h"

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