#include "headers.h"

// comparePages(data1, data2) 
// data1->pages == data2->pages : returns 0
// data1->pages > data2->pages : returns positive number
// data1->pages < data2->pages : returns negative number
int comparePages(void* data1, void* data2) {
	return ((DATA*)data1)->pages - ((DATA*)data2)->pages;
}