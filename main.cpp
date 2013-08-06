#include <stdio.h>
#include <iostream>

extern int yylex(void);
extern FILE*   yyin;

int main() {
	// lex through the input:
	yylex();
	return 0;
		
}
