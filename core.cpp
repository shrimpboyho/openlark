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
	return true;
}

bool Core::isAssignment(std::string testy){
	return true;
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
	this -> currentInstruction = ss;
	
	this -> currentOutput = evalExpression(ss);

}
