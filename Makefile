all:
	bison -d lark.y
	flex lark.l
	g++ lark.tab.c lex.yy.c -L"GnuWin32\lib" -lfl -o build/thing	
