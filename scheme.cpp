#include "core.h"
#include <ctype.h>

void Core::checkDeclaration(){

	/* If declaration with assignment */	
	if(isDeclarationWithAssignment(currentInstruction)){
	
		/* Simplify right hand side */
		simplifyDeclarationWithAssignment();
		
		/* Perform assignment */
		performAssignment("DECASSIGN");

	}else{
		
		/* Create the variable with garbage based on instruction */
		std::vector<std::string> tokens = tokenize(currentInstruction,' ');
		createVar(tokens[1],tokens[0]);

	}

}

void Core::simplifyDeclarationWithAssignment(){

	rightHandSide = currentInstruction.substr(currentInstruction.find("=") + 1);
	std::cout << "RIGHT HAND SIDE: " << rightHandSide << std::endl;
	
	/* See if the right hand side is just a pure math expression that needs to be simplified */
	checkIfPureMath();

	/* If its not see if variables need to be replaced */
	replaceVariablesWithValuesRightHandSide();
	
}

void Core::replaceVariablesWithValuesRightHandSide(){
	/* If its a single variable */

	std::regex singleVarAssignment("^\\s*[a-zA-Z]+|\\s*");

	if(std::regex_match (rightHandSide,singleVarAssignment)){
		std::cout << "REGEX MATCH FOR SINGLE VAR ASSIGNMENT" << std::endl;
		/* Replace the variable with its value */
		rightHandSide = getVarValue(rightHandSide);
	}

	/* TODO: If its more than one variable that needs to be replaced */
	
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

/* Function performs assignment */

void Core::performAssignment(std::string arg){
	
	/* Perform declaration assignement */
	if(arg == "DECASSIGN"){
		std::vector<std::string> tokens = tokenize(currentInstruction,' ');
		createVar(tokens[1],tokens[0]);
		setVarValue(tokens[1], rightHandSide);
	}

	if(arg == "NORMASSIGN"){
		std::vector<std::string> tokens = tokenize(currentInstruction,' ');
		setVarValue(tokens[0], rightHandSide);
	}
	
	
	
}
