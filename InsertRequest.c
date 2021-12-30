#include "headers.h"

// insertRequest(queue, newData) inserts a newData based on its priority and pages
//	 into queue
// returns true if the insert was successful and false otherwise
bool insertRequest(LIST* queue, void* newData) {
	// assign a new node
	LIST_NODE* newnode; // new node
	if (!(newnode = (LIST_NODE*)malloc(sizeof(LIST_NODE)))) { // memory allocation unsuccessful
		return false;
	}
	newnode->dataPtr = newData;
	(queue->count)++; // increment count of queue
	(queue->sequence)++; // increment the sequence (doc num)

	// Case 1: newnode is inserted in the head of queue
	// - head is null						OR 
	// - new priority < current priority	OR
	// - new priority == current priority &&  
	//		new pages < current pages
	if (!(queue->head) || 
		(comparePriority(newData, queue->head->dataPtr) < 0) ||
		((comparePriority(newData, queue->head->dataPtr) == 0) &&
			(comparePages(newData, queue->head->dataPtr) < 0))) {
		newnode->next = queue->head;
		queue->head = newnode;
		return true;
	}

	// Case 2: newnode is inserted in-between the queue
	// - head is not null
	// - new priority < next priority	OR
	// - new priority == next priority &&
	//		new pages < next pages
	LIST_NODE* curnode = queue->head; // current node
	LIST_NODE* nextnode; // pointer to next node
	nextnode = curnode->next;
	while (nextnode) {
		if ((comparePriority(newData, nextnode->dataPtr) < 0) || 
			((comparePriority(newData, nextnode->dataPtr) == 0) &&
				(comparePages(newData, nextnode->dataPtr) < 0))) {
			newnode->next = nextnode;
			curnode->next = newnode;
			return true;
		}
		curnode = nextnode;
		nextnode = nextnode->next;
	}

	// Case 3: newnode is inserted at the end of the queue
	// - head is not null
	// - nextnode is null
	newnode->next = nextnode;
	curnode->next = newnode;
	return true;
}