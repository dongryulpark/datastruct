#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <malloc.h>
#include "doublylinkedlist.h"

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

