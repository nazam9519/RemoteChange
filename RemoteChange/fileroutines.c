#include<stdio.h>
#include"globals.h"
#include"fileroutines.h"

int openFiles() {
	return ((openappend = fopen("C:\\Users\\Nub\\Documents\\testfile.txt", "wb+")) && (parmFile = fopen("C:\\Users\\Nub\\Documents\\remotedef.txt", "r")));
}
void printtoFile(char* string) {
	fprintf(openappend, "%s\n", string);
}
void specialprinttoFile(char* string) {
	fprintf(openappend, "\t%s\n", string);
}