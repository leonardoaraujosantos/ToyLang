/*
 * NFunctionDeclaration.cpp
 *
 *  Created on: 18/03/2012
 *      Author: laraujo
 */

#include "NFunctionDeclaration.hpp"

Value* NFunctionDeclaration::codeGen(CodeGenContext& context)
{
	std::vector<Type*> argTypes;
	std::vector<NVariableDeclaration*>::const_iterator it;

	for (it = arguments.begin(); it != arguments.end(); it++)
	{
		argTypes.push_back(CodeGenContext::typeOf((**it).type));
	}

	llvm::FunctionType *ftype = llvm::FunctionType::get(CodeGenContext::typeOf(type), argTypes, false);

	llvm::Function *function = llvm::Function::Create(ftype, GlobalValue::InternalLinkage, id.name.c_str(), context.module);

	llvm::BasicBlock *bblock = llvm::BasicBlock::Create(getGlobalContext(), "entry", function, 0);

	context.pushBlock(bblock);

	for (it = arguments.begin(); it != arguments.end(); it++)
	{
		(**it).codeGen(context);
	}

	block.codeGen(context);
	llvm::ReturnInst::Create(getGlobalContext(), bblock);

	context.popBlock();
	std::cout << "Creating function: " << id.name << std::endl;
	return function;
}

