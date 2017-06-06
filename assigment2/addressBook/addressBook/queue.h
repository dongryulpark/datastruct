#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "doublylinkedlist.h"
#define NULL '\0'

typedef struct QueueNode {
	doublyLinkedNode* dataNode;
	struct QueueNode* link;
} queueNode;

typedef struct FactorOfQueue {
	queueNode *front, *rear;
} factorOfQueue;

factorOfQueue* getNewQueue();
void getNewQueueNode(factorOfQueue* fQ, doublyLinkedNode* dataNode);

#endif // !_QUEUE_H_

