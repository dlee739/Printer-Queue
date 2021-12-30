#include "headers.h"

// createQueue() creates and returns the queue which is the singly linked list
// note: returns NULL if the dynamic space allocation was unsuccessful
LIST* createQueue(void) {
	LIST* queue; // queue holding linked lists
	if (!(queue = (LIST*)malloc(sizeof(LIST)))) { // dynamic allocation failed
		return NULL;
	}
	if (queue) { // initialize fields
		queue->head = NULL;
		queue->count = 0;
		queue->sequence = 0;
	}
	return queue;
}