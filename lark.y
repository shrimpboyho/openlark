%{
#include <cstdio>
#include <stdio.h>
#include <iostream>
using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
 
void yyerror(const char *s);
%}

// Bison fundamentally works by asking flex to get the next token, which it
// returns as an object of type "yystype".  But tokens could be of any
// arbitrary data type!  So we deal with that in Bison by defining a C union
// holding each of the types of tokens that Flex could return, and have Bison
// use that union instead of "int" for the definition of "yystype":
%union {
	int ival;
	float fval;
	char *sval;
}

// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:
%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING

%%
// this is the actual grammar that bison will parse, but for right now it's just
// something silly to echo to the screen what bison gets from flex.  We'll
// make a real one shortly:
lark:
	lark INT      { cout << "lark found an int: " << $2 << endl; }
	| lark FLOAT  { cout << "lark found a float: " << $2 << endl; }
	| lark STRING { cout << "lark found a string: " << $2 << endl; }
	| INT            { cout << "lark found an int: " << $1 << endl; }
	| FLOAT          { cout << "lark found a float: " << $1 << endl; }
	| STRING         { cout << "lark found a string: " << $1 << endl; }
	;
%%

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

void yyerror(const char *s) {
	cout << "EEK, parse error!  Message: " << s << endl;
	// might as well halt now:
	exit(-1);
}

