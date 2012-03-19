/*
 * NIdentifier.cpp
 *
 *  Created on: 18/03/2012
 *      Author: laraujo
 */
#include "NIdentifier.hpp"

Value* NIdentifier::codeGen(CodeGenContext& context)
{
	std::cout << "Creating identifier reference: " << name << std::endl;
	if (context.locals().find(name) == context.locals().end())
	{
		std::cerr << "undeclared variable " << name << std::endl;
		return NULL;
	}
	return new LoadInst(context.locals()[name], "", false, context.currentBlock());
}
