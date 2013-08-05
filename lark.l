%{
#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex()
%}

FLOAT [0-9]+\.[0-9]+
INTEGER [0-9]+
STRING [a-zA-Z0-9]+

%%

[ \t\n]         ;
{FLOAT}         { cout << "Found a floating-point number:" << yytext << endl; }
{INTEGER}       { cout << "Found an integer:" << yytext << endl; }
{STRING}        { cout << "Found a string: " << yytext << endl; }

%%

int main() {
	// lex through the input:
	yylex();
	return 0;
		
}

