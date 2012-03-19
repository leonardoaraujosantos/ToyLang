/*
 * NBlock.cpp
 *
 *  Created on: 18/03/2012
 *      Author: laraujo
 */

#include "NBlock.hpp"

Value* NBlock::codeGen(CodeGenContext& context)
{
	std::vector<NStatement*>::const_iterator it;
	Value *last = NULL;
	for (it = statements.begin(); it != statements.end(); it++)
	{
		std::cout << "Generating code for " << typeid(**it).name() << std::endl;
		last = (**it).codeGen(context);
	}
	std::cout << "Creating block" << std::endl;
	return last;
}

