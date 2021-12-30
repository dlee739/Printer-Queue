#include "headers.h"

// updateCycles(queue) update the cycle counts of all nodes inside queue
void updateCycles(LIST* queue) {

	LIST_NODE* curnode; // current node
	curnode = queue->head;

	while (curnode) {
		(((DATA*)(curnode->dataPtr))->cycles)++; // increment cycles
		int num = ((DATA*)(curnode->dataPtr))->num; // document number
		int pages = ((DATA*)(curnode->dataPtr))->pages; // document pages
		int priority = ((DATA*)(curnode->dataPtr))->priority; // document priority
		int cycles = ((DATA*)(curnode->dataPtr))->cycles; // document cycles
		if (DEBUG_SHOW_CYCLES) { // CYCLES DEBUG STATEMENT
			printf("Increment Cycle - Document: %d Pages: %d Priority: %d Cycle Count: %d\n",
				num, pages, priority, cycles);
		}

		if (((DATA*)(curnode->dataPtr))->cycles == MAXCYCLES) { // cycles exceeded
			if (DEBUG_SHOW_EXCEEDED) { // EXCEEDED DEBUG STATEMENT
				printf("EXCEEDED CYCLE COUNT - Document: %4d Pages: %4d Priority: %d Cycle Count: %4d\n",
					num, pages, priority, cycles); // message
			}

			// Part (e) - bonus
			((DATA*)(curnode->dataPtr))->priority = 0; // priority set to 0
			removeRequest(queue, curnode); // remove from current position
			insertByPriority(queue, curnode); // insert only based on priority
		}
		curnode = curnode->next; // get next node
	}
}