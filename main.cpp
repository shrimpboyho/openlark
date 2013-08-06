#include <stdio.h>
#include <iostream>

extern "C"
{
	extern int yylex(void);
	extern FILE*   yyin;
}


int main(int argc, char* argv[]) {
	
	/* Invoke the REPL */

	if(argc == 1){
		std::cout << "Welcome to OpenLark \n";
		// lex through the input:
		yylex();
	}

	/* Read from file */

	if(argc > 1){
		std::cout << "Reading from file: " << argv[1] << std::endl;
		yyin = fopen(argv[1],"r");
		yylex();
	}

	return 0;
		
}
