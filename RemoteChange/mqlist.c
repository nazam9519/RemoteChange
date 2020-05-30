#include<stdio.h>
#include<string.h>
#include "mqlist.h"
#include "globals.h"
#include "fileroutines.h"
#include"stringfuncs.h"


void create(ListNodePtr* newPtr) {
	newPtr = malloc(sizeof(listAlias));
	areamalloc++;
}
void stringify(ListNodePtr string, char* s1) {
	string->readstring = malloc(strlen(s1) + 1);                            //initialize string in structure stringList.readstring must (char *) casts the type to a char pointer for malloc since it returns a void pointer
	snprintf(string->readstring, strlen(s1) + 1, s1);
	areamalloc++;
}
int newlist(node** nodedata) {
	int returncode = 0;
	node* new_node;
	if ((new_node = (node*)malloc(sizeof(node))))
		returncode = 4;
	return returncode;
}
void list_init() {
	head = tail = NULL;
}
void list_add_node(node* node) {
	if (NULL == tail) {
		head = tail = node;
		node->next = NULL;
		node->prev = NULL;
	}
	else {
		tail->next = node;
		node->next = NULL;
		node->prev = tail;
		tail = node;
	}
}

node* get_next(node* getnode) {
	if (NULL == getnode) {
		return head;
	}
	else {
		return getnode->next;
	}
}

void set_list(node* nodePtr) {
	
}


void insert(ListNodePtr* startPtr, char* string,ListNodePtr newP) {
	//ListNodePtr newP;
	ListNodePtr prevP;
	ListNodePtr currP;
	
	//newP = malloc(sizeof(listAlias));                                             //allocate memory for new element in list 
	if (newP != NULL) {                                                           //check to see if memory was allocated
		//newP->readstring = malloc(strlen(string) + 1);                            //initialize string in structure stringList.readstring must (char *) casts the type to a char pointer for malloc since it returns a void pointer
		//snprintf(newP->readstring, strlen(string) + 1, string);
		newP->next = NULL;                                                        //set pointer to the next item to be null after updating the element
		prevP = NULL;                                                             //set previous pointer to null
		currP = *startPtr;                                                        //make sure the current pointer = the pointer that was passed (current node in list)
		/*find locationn of item in the list*/
		
		while (currP != NULL) {
			prevP = currP;
			if (strncmp(string, "DEFINE", 6)) {
				if (tracklist == 0) {
					
				}
				else {
					
				}
			}
			currP = currP->next; //next node
		}

		/*insert new node at beginning*/
		if (prevP == NULL) {
			newP->next = *startPtr;
			*startPtr = newP;
		}
		/*insert between two nodes or at the end*/
		else {
			prevP->next = newP;
			newP->next = currP;
		}
	}
	else {
		printf("failed to insert\n");
	}
}
int delete(ListNodePtr* startPtr, char* string) {
	ListNodePtr tempP;
	ListNodePtr prevP;
	ListNodePtr currP;
	printf("\n");
	printf("current string pointer %s %d\n", (*startPtr)->readstring, strlen((*startPtr)->readstring));
	tempP = *startPtr;
	(*startPtr) = (*startPtr)->next;
	free(tempP->readstring);
	free(tempP);
	return 0;
}

int isEmpty(ListNodePtr startPoint) {
	return startPoint == NULL;
}

void printit(ListNodePtr currP) {
	if (currP == NULL) {
		printf("List is Empty\n");
	}
	else {

		fprintf(stdout, "the list is:\n");
		fflush(stdout);
		while (currP != NULL) {
			fprintf(stdout, "%s ->  ", currP->readstring);
			fflush(stdout);
			currP = currP->next;
		}
		printf("NULL\n");
	}
}

//void change(ListNodePtr* currentPtr)
//{
//	ListNodePtr tempP;
//	ListNodePtr currP;
//	finalOP* putOp;
//	char* gettype;
//	static int queuetype;
//	static int changeable;
//
//	tempP = *currentPtr;
//	currP = *currentPtr;
//	currP = currP->next;
//	const char* workstr = "RET.REMOTE.REQUEST";
//	const char* qmgnm = "QMPRET11";
//	const char* xmnm = "QMPIG";
//	char tempCP[23] = { 0 };
//
//	putOp = malloc(sizeof(finalOP));
//
//	while (tempP != NULL) {
//		gettype = getQTypeAttr(tempP->readstring, &queuetype);
//		if (queuetype < 4) {
//			/*stringBuilder(&putOp->QName, ((strlen(gettype) + strlen(workstr)) + 2), gettype, workstr);
//			strcat(putOp->QName, ")");*/
//			changeable = (!strncmp(queuetochange, tempP->readstring + (strlen(gettype)), strlen(queuetochange))) ? 1 : 0;
//			printtoFile(tempP->readstring);
//		}
//		else if (queuetype < 6 && (changeable)) {
//			stringBuilder(&putOp->xmit, ((strlen(gettype) + strlen(xmitq)) + 3), gettype, xmitq);
//			strcat(putOp->xmit, ")");
//			specialprinttoFile(putOp->xmit);
//		}
//		else if (queuetype < 8 && (changeable)) {
//			stringBuilder(&putOp->Rqmgr, ((strlen(gettype) + strlen(qmgr)) + 3), gettype, qmgr);
//			strcat(putOp->Rqmgr, ")");
//			specialprinttoFile(putOp->Rqmgr);
//		}
//
//		else {
//			specialprinttoFile(tempP->readstring);
//		}
//		if (currP == NULL) {
//			tempP = tempP->next;
//		}
//		else {
//			tempP = tempP->next;
//			currP = currP->next;
//		}
//	}
//	if (!changeable) {
//		free(putOp->QName);
//		free(putOp->Rqmgr);
//	}
//	free(putOp);
//}
