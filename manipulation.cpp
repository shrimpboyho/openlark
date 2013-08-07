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

std::vector<std::string> Core::tokenize(std::string thing, char delim){

	std::vector<std::string> tokens;
	std::string package = "";
	std::string backup = "";
	
	bool hit = false;
	int i, k;

	for(i = 0; i < thing.size(); i++){

		/* skip string literals */
		if(thing.at(i) == '"'){
			i++;
			while(thing.at(i) != '"'){
				i++;
			}
		}
		
		/* begin tokenizing */
		if(thing.at(i) != delim){
			package += thing.at(i);
		}else{
			hit = true;
			if(package != ""){
				tokens.push_back(package);
				backup = thing.substr(i+1); 	
				package = "";
			}
			

		}
	}

	if(hit == false){
		tokens.push_back(package);
	}

	if(hit == true){
		tokens.push_back(backup);
	}

	return tokens;

}
