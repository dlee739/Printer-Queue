#include "headers.h"

int main(void) {

	srand(time(NULL)); // randomization initialization

	LIST* queue; // queue of print jobs
	queue = createQueue();
	if (!queue) { // queue can't be created: not enough memory
		return 1;
	}

	for (int i = 1; i <= ITERATIONS; i++) {

		void* newData = createData(queue); // Part (a) - create new data
		if (newData) { // data was created 
			insertRequest(queue, newData); // Part (b) - insert new request 
		}

		popRequest(queue, i); // Part (c) - prints active job
		updateCycles(queue); // Part (d) & (e)

		printList(queue); // prints the entire queue
	}

	printf("End of Program - * DAEHAN LEE *\n");
	printf("Number of printer jobs left in queue: %d\n", queue->count);

	freeQueue(queue); // free the dynamically allocated memory that hasn't been yet

	return 0;
}