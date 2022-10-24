#include "mult.h"

bool ranged(int lo, int hi, char* str) {
	return (lo < str && str < hi);
}
main(int argc, char** argw) {
	if(argc > 1) {
		char *file = argw[1];
		lex(file);
		if(argc > 2) {
			printf("---\n");
			for(int i = 2; i < argc; i++) {
				printf("%s\n", argw[i]);
			}
		}
	} else { printf("mult!\n"); }
	return 0;
}
