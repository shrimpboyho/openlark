#include "core.h"
#include <iostream>
#include <string>

#include <vector>
#include <math.h>
#include <algorithm>


std::string Core::getOutput(){
	return this -> currentOutput;
}

void Core::flush(){
	this -> currentOutput = "";
}

bool Core::isExpression(std::string testy){
	if(testy.find("+") != std::string::npos){
		return true;
	}
	else{
		return false;
	}
}

bool Core::isAssignment(std::string testy){
	if(testy.find("=") != std::string::npos){
		return true;
	}
	else{
		return false;
	}
}

bool Core::isDeclaration(std::string testy){
	if(testy.find("int") != std::string::npos){
		return true;
	}
	else{
		return false;
	}
}

std::string Core::evalExpression(std::string expression){
	ExpressionParser<int> parser;
	return this -> to_string(parser.eval(expression));
}

std::string Core::to_string(int number){
	std::stringstream ss;
    	ss << number;
    	return ss.str();	
}

void Core::feed(std::string ss){
	
	/* Clear the output buffer */
	flush();

	/* Set the current instruction */
	this -> currentInstruction = ss;
	
	/* Check what phase */
	checkDeclaration();
	
}

std::string Core::getVarType(std::string name){
	int i;
	for(i = 0; i < variableNames.size(); i++){
		if(name == variableNames[i]){
			break;
		}
	}
	return variableTypes[i];
}

std::string Core::getVarValue(std::string name){
	int i;
	for(i = 0; i < variableNames.size(); i++){
		if(name == variableNames[i]){
			break;
		}
	}
	return variableValues[i];
}

bool Core::varExists(std::string name){
	int i;
	for(i = 0; i < variableNames.size(); i++){
		if(name == variableNames[i]){
			break;
		}
	}
	if(i != variableNames.size()){
		return true;
	}else{
		return false;
	}
}

void Core::createVar(std::string name, std::string type){
	variableNames.push_back(name);
	variableTypes.push_back(type);
}

void Core::setVarValue(std::string name, std::string value){
	int i;
	for(i = 0; i < variableNames.size(); i++){
		if(name == variableNames[i]){
			variableValues[i] = value;
			break;
		}
	}

}

void Core::checkDeclaration(){
	
	if(isDeclaration(currentInstruction)){
		std::cout << "Declaration found";
		
	}

}

