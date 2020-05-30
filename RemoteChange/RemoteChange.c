#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "globals.h"
#include "fileroutines.h"
#include"mqlist.h"
#include"stringfuncs.h"
#include "listqueue.h"
const char* rqmtypes[remotesynonyms] = {
			"DEFINE QREMOTE(",
			"DEFINE QREMOTE('",
			"DEFINE QR(",
			"DEFINE QR('",
			"XMITQ('",
			"XMITQ(",
			"RQMNAME(",
			"RQMNAME('"
};

int tracklist = 0;
int areamalloc = 0;

int main(int argc, char** argv) {
	char arg1cp[52] = { 0 };
	char arg2cp[52] = { 0 };
	char arg3cp[8] = { 0 };
	int firstcommit = 0;
	node* nodestart;
	ListNodePtr alloc;

	if (argc < 4) {
		printf("please supply the following Remote Queue Name, New XMIT, New RQMgr\n");
		return 8;
	}
	else {

		snprintf(arg1cp, strlen(argv[1]) + 1, argv[1]);
		snprintf(arg2cp, strlen(argv[2]) + 1, argv[2]);
		snprintf(arg3cp, strlen(argv[3]) + 1, argv[3]);
	}
	ListNodePtr startPoint = NULL;                             //first item in the list will now be set to null 
	char fileline[buffsize] = { 0 };
	if (!openFiles()) {
		printf("problems\n");
		return 12;
	}
	else {
		queuetochange = arg1cp;
		xmitq = arg2cp;
		qmgr = arg3cp;
	}
	printf("--------------------------\n");
	printf("Beginning Insert and Print\n");
	printf("--------------------------\n");
	while (fgets(fileline, sizeof(fileline), parmFile) != NULL) {
		strtok(fileline, "\n");
		if (fileline[0] == '*') {
			printtoFile(fileline);
		}
		else if (fileline[0] == '\n') {
			;//do nothing
		}
		else {
			if (!isalpha(fileline[0]))
				checkspace(fileline);
			if (areamalloc == 0) {
				//create(&alloc);
				//newlist(&nodestart);
				create_attr( fileline, strlen(fileline));
			}
			if(areamalloc == 1){
				stringify(&alloc, fileline);
			}
			
				insert(&startPoint, fileline, &alloc);
				firstcommit = 1;
				printit(startPoint);
			
		}
	}
	exit(20);
	//change(&startPoint);
	printf("\n");
	printf("------------------------------\n");
	printf("Delete list from the beginning\n");
	printf("------------------------------\n");
	while (!isEmpty(startPoint)) {
		delete(&startPoint, fileline);
		printit(startPoint);
	}
	return 0;
}





/*	if ((!strncmp(fileline, "DEFINE", 6)) && firstcommit != 0) {
				while (!isEmpty(startPoint)) {
					change(&startPoint);
					delete(&startPoint, fileline); //05/10 where i left off.
					printit(startPoint);
				}
			}*/

