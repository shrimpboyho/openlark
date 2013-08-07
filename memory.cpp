#include "core.h"

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
	variableValues.push_back("GARBAGE");
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

