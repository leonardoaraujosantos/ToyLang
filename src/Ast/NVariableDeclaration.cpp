/*
 * NVariableDeclaration.cpp
 *
 *  Created on: 18/03/2012
 *      Author: laraujo
 */

#include "NVariableDeclaration.hpp"

Value* NVariableDeclaration::codeGen(CodeGenContext& context)
{
	std::cout << "Creating variable declaration " << type.name << " " << id.name << std::endl;
	llvm::AllocaInst *alloc = new llvm::AllocaInst(CodeGenContext::typeOf(type), id.name.c_str(), context.currentBlock());
	context.locals()[id.name] = alloc;
	if (assignmentExpr != NULL)
	{
		NAssignment assn(id, *assignmentExpr);
		assn.codeGen(context);
	}
	return alloc;
}
