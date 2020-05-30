#pragma once
#define buffsize 72
#define remotesynonyms 8
#define subattrsynonym 2

const char* rqmtypes[remotesynonyms];
extern char debug;
char* queuetochange;
char* xmitq;
char* qmgr;
int areamalloc;
int tracklist;
char* temp;

FILE* parmFile;
FILE* openappend;
