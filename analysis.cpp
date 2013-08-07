#include "core.h"

bool Core::isExpression(std::string testy){
	if(testy.find("+") != std::string::npos){
		return true;
	}
	else{
		return false;
	}
}

bool Core::isAssignment(std::string testy){
	if(testy.find(" = ") != std::string::npos){
		return true;
	}
	else{
		return false;
	}
}

bool Core::isDeclaration(std::string testy){
	if(testy.find("int ") != std::string::npos){
		return true;
	}
	else{
		return false;
	}
}

bool Core::isDeclarationWithAssignment(std::string testy){
	if(testy.find("int ") != std::string::npos && 
			testy.find("int ") != std::string::npos){
		return true;
	}
	else{
		return false;
	}
}
