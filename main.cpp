#include <stdio.h>
#include <iostream>

extern "C"
{
	extern int yylex(void);
	extern FILE*   yyin;
}


int main() {
	
	std::cout << "Welcome to OpenLark \n";

	// lex through the input:
	yylex();
	return 0;
		
}
