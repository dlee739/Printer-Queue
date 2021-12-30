#ifndef dH
#define dH

// DEBUG statements
#define DEBUG_LIST 1 // prints entire data inside list
#define DEBUG_ADDING 1 // prints the added data
#define DEBUG_PRINT_PROCESS 1 // prints the printing process
#define DEBUG_SHOW_CYCLES 1 // prints the increments of cycles
#define DEBUG_SHOW_EXCEEDED 1 // prints an exceeded status


// Macro definitions
#define PAGESPERMINUTE 1 // pages printed per iteration
#define MAXCYCLES 200  // maximum number of cycles of each print jobs
#define MAXPAGES 30  // maximum pages of each print jobs 
#define ITERATIONS 1000 // number of total iterations


// Structures
typedef struct node // structure of a node
{
	void* dataPtr; // pointer to document structure
	struct node* next; // must be a singly linked list
} LIST_NODE;

typedef struct document // data
{
	int num; // document number
	int priority; // priority level
	int pages; // number of pages
	int cycles; // cycles
} DATA;

typedef struct linkedList // queue
{
	LIST_NODE* head; // front of LIST
	int count; // count of nodes in LIST
	int sequence; // sequence of nodes (document number)
} LIST;


// Methods
void* createData(LIST* queue);

LIST* createQueue(void);

void popRequest(LIST* queue, int curIterations);

bool insertRequest(LIST* queue, void* newData);

void updateCycles(LIST* queue);

int comparePages(void* data1, void* data2);

int comparePriority(void* data1, void* data2);

void printList(LIST* queue);

void removeRequest(LIST* queue, LIST_NODE* request);

void insertByPriority(LIST* queue, LIST_NODE* request);

void freeQueue(LIST* queue);

#endif // dH


