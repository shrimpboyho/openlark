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
	
	int i;

	for(i = 0; i < objectTypes.size(); i++){
		if(testy.find(objectTypes[i] + " ") != std::string::npos){
			std::cout << "Found " + objectTypes[i] + " declaration\n";
			return true;
		}
	}
	
	return false;
}

/* TODO: FIX THIS */

bool Core::isDeclarationWithAssignment(std::string testy){

	int i;

	for(i = 0; i < objectTypes.size(); i++){
		if(testy.find(objectTypes[i] + " ") != std::string::npos && testy.find(" = ") != std::string::npos){
			std::cout << "Found " + objectTypes[i] + " declaration\n";
			return true;
		}
	}
	
	return false;
}
