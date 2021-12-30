#include "headers.h"

// freeQueue(queue) free up the dynamically-allocated memory of data, nodes, and queue
//   itself.
void freeQueue(LIST* queue) {
	LIST_NODE* curnode = queue->head; // current node pointing to head
	LIST_NODE* temp = NULL; // temporary node

	while (curnode) { // more memory to free
		temp = curnode;
		curnode = curnode->next;
		free(temp->dataPtr);
		free(temp);
	}
	free(queue);
}