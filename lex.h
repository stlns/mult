#ifndef LEX_H
#define LEX_H

#include <stdio.h>
#include <stdlib.h>

char temp[256];
enum state { IDLE, YIELD, OPER, CHAR, NUM };

void lex(char* file);

#endif