#include "tools/parser.h"
#include <iostream>
#include <vector>
#include <string.h>

class Core{

	private:

		/* Time and state variables */

		std::string currentInstruction;
		std::string currentOutput;
		
		/* System memory */
		
		std::vector<std::string> variableTypes;
		std::vector<std::string> variableValues;
		std::vector<std::string> variableNames;

		std::string getVarType(std::string name);
		std::string getVarValue(std::string name);
		bool varExists(std::string name);
		void createVar(std::string name, std::string type);
		void setVarValue(std::string name, std::string value);

		/* Parsing and analysis functions */

		void checkDeclaration();
		void simplifyVariables();
		void evaluateRightHandSide();
		void performAssignment();
		bool isExpression(std::string testy);
		bool isAssignment(std::string testy);
		bool isDeclaration(std::string testy);

		/* Math functions */

		std::string evalExpression(std::string expression);

		/* Helper functions */

		std::string to_string(int number);
	
	public:
		
		/* Loads instruction */
		
		void feed(std::string ss);

		/* Clears instruction */

		void flush();

		/* Get output to feed to REPL */

		std::string getOutput();

};
