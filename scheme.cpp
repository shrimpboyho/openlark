#include "core.h"

void Core::checkDeclaration(){
	
	if(isDeclarationWithAssignment(currentInstruction)){
	
		simplifyDeclarationWithAssignment();
		// evalExpression()
	}else{
		
		// Create the variable with garbage
		std::vector<std::string> tokens = tokenize(currentInstruction,' ');
		createVar(tokens[1],tokens[0]);

	}

}

void Core::simplifyDeclarationWithAssignment(){

	rightHandSide = currentInstruction.substr(currentInstruction.find("=") + 1);
	std::cout << "RIGHT HAND SIDE: " << rightHandSide << std::endl;
	replaceVariablesWithValuesRightHandSide();
	
}

void Core::replaceVariablesWithValuesRightHandSide(){
	/* Check to see if things need to be replaced */
	std::vector<std::string> stuff = tokenize(rightHandSide,' ');
	int i;

	for(i = 0; i < stuff.size(); i++){
		std::cout << "STUFF: " << stuff[i];
	}
}
