%{
#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex()
%}

FLOAT [0-9]+\.[0-9]+
INTEGER [0-9]+
STRING [a-zA-Z0-9]+
ASSIGNOP [=]
ADDOP [+]
SUBOP [-]
MULTIPLYOP [*]
DIVIDEOP [/]

%%

[ \t\n]         ;
{FLOAT}         { cout << "Found a floating-point number:" << yytext << endl; }
{INTEGER}       { cout << "Found an integer:" << yytext << endl; }
{STRING}        { cout << "Found a string: " << yytext << endl; }
{ADDOP}         { cout << "Found an addition operator: " << yytext << endl; }
{SUBOP}         { cout << "Found a subtraction operator: " << yytext << endl; }
{MULTIPLYOP}    { cout << "Found a multiplication operator: " << yytext << endl; }
{DIVIDEOP}      { cout << "Found a division operator: " << yytext << endl; }
{ASSIGNOP}      { cout << "Found an assignment operator: " << yytext << endl; }

%%

