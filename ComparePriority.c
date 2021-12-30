#include "headers.h"

// comparePriority(data1, data2) 
// data1->priority == data2->priority : returns 0
// data1->priority > data2->priority : returns positive number
// data1->priority < data2->priority : returns negative number
int comparePriority(void* data1, void* data2) {
	return ((DATA*)data1)->priority - ((DATA*)data2)->priority;
}