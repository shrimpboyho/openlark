#include "core.h"
#include <ctype.h>

void Core::checkDeclaration(){
	
	if(isDeclarationWithAssignment(currentInstruction)){
	
		simplifyDeclarationWithAssignment();
		
		// Perform assignment
		
		performAssignment();

	}else{
		
		// Create the variable with garbage
		std::vector<std::string> tokens = tokenize(currentInstruction,' ');
		createVar(tokens[1],tokens[0]);

	}

}

void Core::simplifyDeclarationWithAssignment(){

	rightHandSide = currentInstruction.substr(currentInstruction.find("=") + 1);
	std::cout << "RIGHT HAND SIDE: " << rightHandSide << std::endl;
	checkIfPureMath();
	replaceVariablesWithValuesRightHandSide();
	
}

void Core::replaceVariablesWithValuesRightHandSide(){

	std::vector<std::string> stuff = tokenize(rightHandSide,' ');
	
	int i;

	for(i = 0; i < stuff.size(); i++){
		std::cout << "STUFF: " << stuff[i];
	}
}

void Core::checkIfPureMath(){
		/* Check to see if things need to be replaced in the first place (could just be a math expression)*/
	int i;

	for(i = 0; i < rightHandSide.size(); i++){
		if(isalpha(rightHandSide.at(i))){
			break;
		}
	}

	if(i == rightHandSide.size()){
		rightHandSide = evalExpression(rightHandSide);
	}
}

void Core::performAssignment(){
	std::vector<std::string> tokens = tokenize(currentInstruction,' ');
	createVar(tokens[1],tokens[0]);
	setVarValue(tokens[1], rightHandSide);
}
