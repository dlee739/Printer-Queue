#include "headers.h"

// createData(queue) depending on set of probabilities, creates the print jobs
//	  and returns it
// note: some fields of the new print job is decided randomly, some are not.
void* createData(LIST* queue) {

	DATA* doc = NULL; // data document

	int chance = rand() % 10; // rng between 0 and 9 (10 numbers)
	if (chance == 0) { // probability: 1 out of 10 (10%)
		if (!(doc = (DATA*)malloc(sizeof(DATA)))) {
			return NULL;
		}

		// assign priority of doc
		chance = rand() % 10; // re-roll between 0 and 9 (10 numbers)
		if (chance == 0) { // probability: 1 out of 10 (10%)
			doc->priority = 1; // high priority
		}
		else if (chance >= 1 && chance <= 7) { // probability: 7 out of 10 (70%)
			doc->priority = 2; // average priority
		}
		else { // probability: 2 out of 10 (20%)
			doc->priority = 3; // low priority 
		}

		// assign rest of data into doc[ument]
		int pageNum = (rand() % (MAXPAGES + 1)) + 1; // random number of pages in [0, MAXPAGES]
		doc->num = queue->sequence + 1;
		doc->pages = pageNum;
		doc->cycles = 0;

		if (DEBUG_ADDING) { // DEBUG STATEMENT
			printf("\nAdding to Queue - Doc: %2d NoPages: %2d Priority: %2d\n",
				doc->num, doc->pages, doc->priority); 
		}
	}

	return doc;
}