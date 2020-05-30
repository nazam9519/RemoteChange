#include<stdio.h>
#include"globals.h"
#include "stringfuncs.h"

void stringBuilder(char** strptr, size_t allocsz, char* formatter, char* formatter2) {
	char* newstr = malloc(allocsz);
	snprintf(newstr, strlen(formatter) + 1, formatter);
	strcat(newstr, formatter2);
	*strptr = newstr;
}
void appendStr(char* string, char* appendelement) {
	strcat(string, appendelement);
}
char* getQTypeAttr(char* data, int* type)
{
	for (*type = 0; (*type) != remotesynonyms; (*type)++) {
		if (!strncmp(data, rqmtypes[*type], strlen(rqmtypes[*type])))
			return rqmtypes[*type];
	}
}

void checkspace(char* buffer) {
	for (int i = 0; i < strlen(buffer); i++) {
		if (!isspace(buffer[i])) {
			snprintf(buffer, strlen(buffer), buffer + i);
			break;
		}
	}
}


void checkplus(char* buffer)
{

}
