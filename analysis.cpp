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
	
	std::vector<std::string> tokens = tokenize(currentInstruction,' ');

	for(i = 0; i < objectTypes.size(); i++){
		if(tokens[0] == objectTypes[i]){
			std::cout << "Found " + objectTypes[i] + " declaration\n";
			return true;
		}
	}
	
	return false;
}

/* TODO: FIX THIS */

bool Core::isDeclarationWithAssignment(std::string testy){

	int i;

	std::vector<std::string> tokens = tokenize(currentInstruction,' ');

	for(i = 0; i < objectTypes.size(); i++){
		if(tokens[0] == objectTypes[i] && testy.find(" = ") != std::string::npos){
			std::cout << "Found " + objectTypes[i] + " declaration with assignment\n";
			return true;
		}
	}
	
	return false;
}

bool Core::checkIfPureMath(std::string s){
		/* Check to see if things need to be replaced in the first place (could just be a math expression)*/
	int i;

	for(i = 0; i < s.size(); i++){
		if(isalpha(s.at(i))){
			break;
		}
	}

	if(i == s.size()){
		return true;
	}

	return false;
}

