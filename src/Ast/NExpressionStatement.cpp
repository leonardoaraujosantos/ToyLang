/*
 * NExpressionStatement.cpp
 *
 *  Created on: 18/03/2012
 *      Author: laraujo
 */

#include "NExpressionStatement.hpp"

Value* NExpressionStatement::codeGen(CodeGenContext& context)
{
	std::cout << "Generating code for " << typeid(expression).name() << std::endl;
	return expression.codeGen(context);
}


