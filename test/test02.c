#include <stdio.h>
#include "io.h"

int main (void) {

	int i;
	short j;
	int word;
	short half;
	
	FILE *f=fopen("dat.bin", "w+b");
	if (f==NULL) {
		printf("Nije moguce otvoriti datoteku.\n");
		return 0;
	}
	for (i=0; i<10; i++) {
		write_word(f, i);
		printf("Upisujem : %d\n", i);				
	}

	fseek(f, 0, SEEK_SET);	

	for (i=0; i<10; i++) {
		word=read_word(f);
		printf("Citam: %d\n", word);
	}
		
	for (j=0; j<10; j++) {
		write_half(f, j);
		printf("Upisujem: %d\n", j);
	}

	fseek(f, 10*sizeof(int), SEEK_SET);

	for (i=0; i<10; i++) {
		half=read_half(f);
		printf("Citam: %hd\n", half);
	}
	
	fclose(f);
	return 0;
}
		
	
		

	
