#include "headers.h"

// removeRequest(queue, request) removes request (does not free) from queue
// requires: queue is not empty
//			 request is inside of queue
void removeRequest(LIST* queue, LIST_NODE* request) {
	 LIST_NODE* curnode = queue->head; // current node
	 LIST_NODE* prevnode = NULL; // previous node

	while (curnode && curnode != request) { // search for request
		prevnode = curnode;
		curnode = curnode->next;
	}

	if (curnode == queue->head) { // request is in front of queue
		queue->head = curnode->next;
	}
	else { // request is inbetween the queue
		prevnode->next = curnode->next;
	}
	(queue->count)--; // decrement count
}