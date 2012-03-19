/*
 * NAssignment.cpp
 *
 *  Created on: 18/03/2012
 *      Author: laraujo
 */

#include "NAssignment.hpp"

Value* NAssignment::codeGen(CodeGenContext& context)
{
	std::cout << "Creating assignment for " << lhs.name << std::endl;
	if (context.locals().find(lhs.name) == context.locals().end())
	{
		std::cerr << "undeclared variable " << lhs.name << std::endl;
		return NULL;
	}
	return new StoreInst(rhs.codeGen(context), context.locals()[lhs.name], false, context.currentBlock());
}


