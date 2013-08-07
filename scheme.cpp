#include "core.h"

void Core::checkDeclaration(){
	
	if(isDeclarationWithAssignment(currentInstruction)){
	
		simplifyDeclarationWithAssignment();

	}

}

void Core::simplifyDeclarationWithAssignment(){

}
