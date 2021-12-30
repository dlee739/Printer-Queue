#include "headers.h"

// popRequest(queue, curInterations) manages the current active print job
//	  and pops out the frontmost node when there are no active job.
// note: frees the memory allocated by current active job, if the current iteration
//			is the last run
void popRequest(LIST* queue, int curInterations) {
	static DATA* curJob = NULL;// current print job in progress
	if (!curJob && !(queue->head)) { // no current job and empty queue
		return;
	}
	else if (!curJob) { // no current active print job in progress
		LIST_NODE* curnode = queue->head; // current node
		curJob = (DATA*)(curnode->dataPtr); 

		// pop the curnode from queue
		queue->head = curnode->next;
		(queue->count)--; // decrement count
		free(curnode); // remove current node from the queue
	}

	curJob->pages -= PAGESPERMINUTE; // decrement pages

	if (DEBUG_PRINT_PROCESS) { // PRINT DEBUG STATEMENT
		printf("PRINTING - DOCUMENT: %4d PAGE: %4d priority: %d\n",
			curJob->num, curJob->pages, curJob->priority);
	}

	if (curJob->pages <= 0) { // all pages are printed
		printf("Print Job Completed - Document Number: %4d   -   Cycle Count: %4d\n",
			curJob->num, curJob->cycles);
		free(curJob);
		curJob = NULL; // points back to NULL
	}

	if (curInterations == ITERATIONS) { // frees current active job at the last iteration
		free(curJob);
	}
}