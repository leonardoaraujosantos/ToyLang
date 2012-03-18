/*
 * main.cpp
 *
 *  Created on: 18/03/2012
 *      Author: laraujo
 */

#include <iostream>

// Include headers of ast
#include "Ast/Node.hpp"
#include "Ast/NBlock.hpp"
#include "Ast/NStatement.hpp"
#include "Ast/NExpression.hpp"
#include "Ast/NIdentifier.hpp"
#include "Ast/NVariableDeclaration.hpp"

extern NBlock* programBlock;
extern int yyparse();

int main(int argc, char **argv)
{
	yyparse();
	std::cout << programBlock << std::endl;
	return 0;
}
