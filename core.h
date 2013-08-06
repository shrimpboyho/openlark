#include "tools/parser.h"
#include <iostream>
#include <vector>


class Core{

	private:

		/* Time and state variables */

		std::string currentInstruction;
		std::string currentOutput;
		
		/* System memory */
		
		std::vector<std::string> memory;
		std::vector<std::string> memoryType;

		/* Parsing and analysis functions */

		bool isExpression(std::string testy);
		bool isAssignment(std::string testy);

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
