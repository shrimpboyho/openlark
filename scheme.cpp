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

}
