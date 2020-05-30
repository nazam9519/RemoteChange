#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"listqueue.h"
#include"mqlist.h"

//int alloc_subattr(queuesubattr** subd, void* data, size_t data_size)
//{
//	int returncode = 0;
//	queuesubattr* new_subattr;
//	if(!(new_subattr = (queuesubattr*)malloc(sizeof(queuesubattr))))
//		returncode = 4;
//	return returncode; 
//}

void set_subattr(queuesubattr** subd, void* data, size_t data_size)
{
	
}

void create_attr(char* data, size_t data_size) {
	struct qsubattr* new_queue = (struct qsubattr*)malloc(sizeof(struct qsubattr));
	//(char *)new_queue->noded = malloc(data_size);
	list_init();
	char* copyfileline;
	copyfileline = malloc((strlen(data))+1);
	snprintf(copyfileline,data_size,data);
	new_queue->noded = copyfileline;
	new_queue->node1.data = (char *)new_queue->data;
	//a->
	list_add_node((node*)new_queue);
}