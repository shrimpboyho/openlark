#include "core.h"

std::string Core::evalExpression(std::string expression){
	ExpressionParser<int> parser;
	return this -> to_string(parser.eval(expression));
}

std::string Core::to_string(int number){
	std::stringstream ss;
    	ss << number;
    	return ss.str();	
}
