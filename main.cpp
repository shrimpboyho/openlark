#include <stdio.h>
#include <iostream>
#include "core.h"

int main(int argc, char* argv[]) {
	
	/* Invoke the REPL */

	if(argc == 1){
		std::cout << "Welcome to OpenLark \n";
		std::string input;
		
		/* Create a core */
		Core CORE;

		/* Load the core with arguments (variables) */

		ARG_STRUCT a;
		a.argNames.push_back("bsp");
		a.argTypes.push_back("int");
		a.argValues.push_back("0");

		CORE.loadArgs(a);
		
		/* Begin the REPL */

		while(1 == 1){
			std::cout << ">>> ";
			std::getline(std::cin,input);
			CORE.feed(input);
			std::cout << CORE.getOutput() << std::endl;
			CORE.printMemory();
			
		}

	}

	/* Read from file */

	if(argc > 1){
		
		/* make sure it is valid: */
		FILE* myfile = fopen(argv[1],"r");	
		if (!myfile) {
			std::cout << "I can't open the file!" << std::endl;
			return -1;
		}
		std::cout << "Reading from file: " << argv[1] << std::endl;
	}

	return 0;
		
}
