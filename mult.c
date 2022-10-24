#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool ranged(int lo, int hi, char* str) {
	return (lo < str && str < hi);
}
void lex(char *file) {
	FILE *f = fopen(file, "r"); char ch;
	if(f != NULL) {
		while((ch = fgetc(f)) != EOF) {
			switch(ch) {
				case '\n': case '\t': case ' ': continue;
				case '(': case ')': case '{': case '}': case '[': case ']': case ',': case ';': case '=': case ':': case '"': printf("yield = %c \n", ch); continue;
				case '+': case '-': case '*': case '/': case '\\': printf("oper %c\n", ch); continue;
				case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': printf("num = %c\n", ch); continue;
				default: printf("? = %c\n", ch); continue;
			}
		}
	} else { printf("file not found\n"); }
	fclose(f);
}
main(int argc, char** argw) {
	if(argc > 1) {
		if(argc > 2) {
			for(int i = 1; i < argc; i++) {
				if(ranged(0, 72, atoi(argw[i])))
					printf("in range = %s\n", argw[i]);
				else
					printf("%s\n", argw[i]);
			}
		} else {
			char *file = argw[1];
			lex(file);
		}
	} else { printf("mult!\n"); }
	return 0;
}