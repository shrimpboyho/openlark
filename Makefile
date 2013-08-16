all:
	g++ main.cpp core.cpp analysis.cpp memory.cpp manipulation.cpp scheme.cpp -std=c++0x -o build/thing
	./build/thing	
