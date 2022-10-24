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
				case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z': case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z': {
					printf("char = %c\n", ch); continue;
				}
				default: printf("? = %c\n", ch); continue;
			}
		}
	} else { printf("file not found\n"); }
	fclose(f);
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