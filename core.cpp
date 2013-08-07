#include "core.h"

std::string Core::getOutput(){
	return this -> currentOutput;
}

void Core::flush(){
	this -> currentOutput = "";
}

void Core::feed(std::string ss){
	
	/* Clear the output buffer */
	flush();

	/* Set the current instruction */
	this -> currentInstruction = ss;
	
	/* Check what phase */
	checkDeclaration();
	
}

