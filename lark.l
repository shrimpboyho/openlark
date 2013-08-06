%{
#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex()

#include "lark.tab.h"  // to get the token types that we return
%}

FLOAT [0-9]+\.[0-9]+
INTEGER [0-9]+
STRING [a-zA-Z0-9]+
ASSIGNOP "="
ADDOP [+]
SUBOP [-]
MULTIPLYOP [*]
DIVIDEOP [/]
EQUALSOP "=="

%%

[ \t\n]         ;
{FLOAT}         { 
		  cout << "Found a floating-point number: " << yytext << endl; 
		  yylval.fval = atof(yytext); 
		  return FLOAT;
		}
{INTEGER}       { cout << "Found an integer: " << yytext << endl; 
		  yylval.ival = atoi(yytext); 
		  return INT;
		}
{STRING}        { cout << "Found a string: " << yytext << endl; 
		  // we have to copy because we can't rely on yytext not changing underneath us:
		  yylval.sval = strdup(yytext);
		  return STRING;
		  
		}
{ADDOP}         { cout << "Found an addition operator: " << yytext << endl; }
{SUBOP}         { cout << "Found a subtraction operator: " << yytext << endl; }
{MULTIPLYOP}    { cout << "Found a multiplication operator: " << yytext << endl; }
{DIVIDEOP}      { cout << "Found a division operator: " << yytext << endl; }
{ASSIGNOP}      { cout << "Found an assignment operator: " << yytext << endl; }
{EQUALSOP}      { cout << "Found an equals operator: " << yytext << endl; }
.               { printf("Unknown token!\n"); yyterminate(); }

%%

