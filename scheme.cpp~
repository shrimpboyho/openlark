#include "core.h"
#include <ctype.h>

/* Handles any calls to built in features (functions, etc) */

void Core::checkBuiltIns(){
	
	/* HANDLE THE BUILT IN PRINT COMMAND */
	int i;
	std::vector<std::string> tokens = tokenize(currentInstruction,' ');
	if(tokens[0] == "print"){
		std::string everythingElse = "";
		for(i = 1; i < tokens.size(); i++){
			everythingElse += " " + tokens[i];	
		}
		currentOutput = simplificationLoop(everythingElse);
	}

	

}

/* Handles declarations */

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
	rightHandSide = clearLeadingWhitespace(rightHandSide);
	std::cout << "RIGHT HAND SIDE: " << rightHandSide << std::endl;
	
	/* See if the right hand side is just a pure math expression that needs to be simplified */
	if(checkIfPureMath(rightHandSide) == true){
		rightHandSide = evalExpression(rightHandSide);
	}else{
		/* If its not see if variables need to be replaced */
		replaceVariablesWithValuesRightHandSide();
	}
	
}

void Core::replaceVariablesWithValuesRightHandSide(){
	/* If its a single variable */

	int pos = 0;
	
	// Skip leading whitespace
	while(rightHandSide.at(pos) == ' '){
		pos++;
	}

	for(pos; pos < rightHandSide.size(); pos++){
		// if its not a single simple variable
		if(!isalpha(rightHandSide.at(pos))){
			break;
		}
	}

	if(pos == rightHandSide.size()){
		std::cout << "MATCH FOR SINGLE VAR ASSIGNMENT" << std::endl;
		/* Replace the variable with its value */
		rightHandSide = getVarValue(rightHandSide);
	}

	/* TODO: If its more than one variable that needs to be replaced */
	
	else{
		rightHandSide = simplificationLoop(rightHandSide);
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

std::string Core::simplificationLoop(std::string s){
	
	/* TODO: MAKE THIS PARSER BETTER */

	int i;
	for(i = 0; i < variableNames.size(); i++){

		s = pystring::replace(s, variableNames[i], variableValues[i]);

	}
	return evalExpression(s);
}
