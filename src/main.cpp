/*
 * main.cpp
 *
 *  Created on: 18/03/2012
 *      Author: laraujo
 */

#include <iostream>

#include "CodeGenContext.hpp"

extern NBlock* programBlock;
extern int yyparse();

int main(int argc, char **argv)
{
	yyparse();
	std::cout << programBlock << std::endl;

	InitializeNativeTarget();
	CodeGenContext context;
	context.generateCode(*programBlock);
	context.runCode();

	return 0;
}
