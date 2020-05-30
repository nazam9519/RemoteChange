#pragma once

struct stringList {
	void* readstring;               //pointer to string  
	struct stringList* next;        //pointer to next item in list 
};

typedef struct n1 node;
struct n1 {
	void* data;
	node* next;
	node* prev;
};

typedef struct {
	char* QName;
	char* Rqmgr;
	char* xmit;
}finalOP;

typedef struct stringList listAlias; //create ListAlias type (alias to StringList struct)
typedef listAlias* ListNodePtr;      //pointer to stringList
node* head;
node* tail;

void list_add_node(struct list_node* node);
int newlist(node** nodedata);
void list_init();
node* get_next(node*);
void set_list(node** nodeptr,void *data,size_t data_size);
void insert(ListNodePtr* startPtr, char* string,ListNodePtr newP);                   //init functions 
int delete(ListNodePtr* startPtr, char* string);
int isEmpty(ListNodePtr startPtr);
void printit(ListNodePtr currentPtr);
void change(ListNodePtr* currentPtr);
void create(ListNodePtr* startPtr);
void stringify(ListNodePtr, char*);


