#pragma once
#include"mqlist.h"
typedef struct qsubattr queuesubattr;
struct qsubattr {
	void* noded;
	void* data;
	struct n1 node1;
	queuesubattr* next;
};

//int alloc_subattr(queuesubattr** subd, void* data, size_t data_size);
//void set_subattr(queuesubattr** subd,void* data,size_t data_size);
void create_attr(char* data, size_t data_size);