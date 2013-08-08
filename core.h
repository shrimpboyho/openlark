#include "tools/parser.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <regex>

class Core{

	private:

		/* Language variables */

		std::vector<std::string> objectTypes;
		
		/* Time and state variables */

		std::string currentInstruction;
		std::string rightHandSide;
		std::string leftHandSide;
		std::string currentOutput;
		
		/* System memory stuff */
		
		std::vector<std::string> variableTypes;
		std::vector<std::string> variableValues;
		std::vector<std::string> variableNames;

		std::string getVarType(std::string name);
		std::string getVarValue(std::string name);
		bool varExists(std::string name);
		void createVar(std::string name, std::string type);
		void setVarValue(std::string name, std::string value);

		/* Interpreting functions */

		void checkDeclaration();
		void checkIfPureMath();
		void replaceVariablesWithValuesRightHandSide();
		void performAssignment(std::string arg);
		void simplifyDeclarationWithAssignment();

		/* Analysis functions */

		bool isExpression(std::string testy);
		bool isAssignment(std::string testy);
		bool isDeclaration(std::string testy);
		bool isDeclarationWithAssignment(std::string testy);

		/* Math functions */

		std::string evalExpression(std::string expression);

		/* Helper functions */

		std::string to_string(int number);
		std::vector<std::string> tokenize(std::string thing, char delim);
	
	public:
		
		/* Constructor */
		Core();
		
		/* Loads instruction */
		void feed(std::string ss);

		/* Clears instruction */
		void flush();

		/* Get output to feed to REPL */
		std::string getOutput();
		
		/* Debugging purposes */
		void printMemory();
};
