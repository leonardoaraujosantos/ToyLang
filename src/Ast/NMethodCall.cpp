/*
 * NMethodCall.cpp
 *
 *  Created on: 18/03/2012
 *      Author: laraujo
 */

#include "NMethodCall.hpp"

Value* NMethodCall::codeGen(CodeGenContext& context)
{
	Function *function = context.module->getFunction(id.name.c_str());
	if (function == NULL)
	{
		std::cerr << "no such function " << id.name << std::endl;
	}
	std::vector<Value*> args;
	std::vector<NExpression*>::const_iterator it;
	for (it = arguments.begin(); it != arguments.end(); it++)
	{
		args.push_back((**it).codeGen(context));
	}

	// Create an LLVM IR for calling methods...
	llvm::CallInst *call = llvm::CallInst::Create(function,  args, std::string(""), context.currentBlock());

	std::cout << "Creating method call: " << id.name << std::endl;
	return call;
}

