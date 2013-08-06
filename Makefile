all:
	flex lark.l
	g++ lex.yy.c main.cpp -L"GnuWin32\lib" -lfl -o build/thing	
