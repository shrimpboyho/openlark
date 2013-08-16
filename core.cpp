#include "core.h"

Core::Core(){

	/* Load up with default types */
	objectTypes.push_back("int");
	objectTypes.push_back("float");
	objectTypes.push_back("string");

}

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
	
	/* Get instruction tokens and print them out */
	std::vector<std::string> tokens = tokenize(currentInstruction,' ');	
	int i;
	for(i = 0; i < tokens.size(); i++){
		std::cout << "TOKENS: " << tokens[i] << std::endl;
	}	

	/* Interpret the instruction */
	
	if(isDeclaration(currentInstruction)){
		checkDeclaration();
	}
	
	
	
}

