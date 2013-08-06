#include <stdio.h>
#include <iostream>

extern "C"
{
	extern int yylex(void);
	extern int yyparse(void);
	extern FILE* yyin;
}

void yyerror(const char *s);

int main(int argc, char* argv[]) {
	
	/* Invoke the REPL */

	if(argc == 1){
		std::cout << "Welcome to OpenLark \n";
		// lex through the input:
		yylex();
	}

	/* Read from file */

	if(argc > 1){
		
		// make sure it is valid:
		FILE* myfile = fopen(argv[1],"r");	
		if (!myfile) {
			std::cout << "I can't open the file!" << std::endl;
			return -1;
		}
		std::cout << "Reading from file: " << argv[1] << std::endl;
		yyin = myfile;
		
		// parse through the input until there is no more:
		
		do {
			yyparse();
		} while (!feof(yyin));
	}

	return 0;
		
}

/* This function doesn't work yet. But it will soon. */

void yyerror(const char *s) {
	std::cout << "EEK, parse error!  Message: " << s << std::endl;
	// might as well halt now:
	
}

