#include "headers.h"

// printList(queue) prints all the linked nodes inside the queue
void printList(LIST* queue) {
	if (!DEBUG_LIST) { // LIST DEBUG STATEMENT (set to false)
		return;
	}
	
	if (queue->head == NULL) { // queue is empty
		printf("EMPTY QUEUE - no print jobs currently in queue\n");
	}
	else {
		LIST_NODE* curnode; // current node
		curnode = queue->head;

		printf("\nCurrent Printer Queue Size: %d\n", queue->count);
		while (curnode) { // print listing of every jobs in queue
			int num = ((DATA*)(curnode->dataPtr))->num; // document number
			int pages = ((DATA*)(curnode->dataPtr))->pages; // number of pages
			int priority = ((DATA*)(curnode->dataPtr))->priority; // priority level
			int cycles = ((DATA*)(curnode->dataPtr))->cycles; // number of cycles
			printf("Current Printer Queue : DocNum: %d  NumofPages %d  PriorityLevel %d  NumOfCycles %d\n", 
				num, pages, priority, cycles);

			curnode = curnode->next; // update curnode
		}
		printf("END OF LIST\n\n");
	}
}