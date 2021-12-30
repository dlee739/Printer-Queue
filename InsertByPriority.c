#include "headers.h"

// insertByPrority(queue, request) inserts request into queue based only on its priority
void insertByPriority(LIST* queue, LIST_NODE* request) {
	(queue->count)++; // increment count

	// Case 1: newnode is inserted in the head of queue
	// - head is null						OR 
	// - new priority < current priority
	if (!(queue->head) || 
		(comparePriority(request->dataPtr, queue->head->dataPtr) < 0)) {
		request->next = queue->head;
		queue->head = request;
		return;
	}

	// Case 2: newnode is inserted in-between the queue
	// - head is not null					AND
	// - new priority < next priority
	LIST_NODE* curnode = queue->head; // current node
	LIST_NODE* nextnode; // pointer to next node
	nextnode = curnode->next;
	while (nextnode && (comparePriority(request->dataPtr, nextnode->dataPtr) >= 0)) {
		curnode = nextnode;
		nextnode = nextnode->next;
	}
	request->next = nextnode;
	curnode->next = request;
}