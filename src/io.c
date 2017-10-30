#include<stdio.h>
#include "io.h"

int read_word (FILE *fd) {
	int word;
	fread(&word,sizeof(int),1,fd);
   	return word;
}

short read_half(FILE *fd) {
	short half;
	fread(&half,sizeof(short),1,fd);
	return half;
}

void write_word(FILE *fd, int word) {
	fwrite(&word,sizeof(int),1,fd);
}

void write_half(FILE *fd, short word) {
	fwrite(&word,sizeof(short),1,fd);
}
