/*
 * CodeGenContext.cpp
 *
 *  Created on: Mar 19, 2012
 *      Author: laraujo
 */

#include "CodeGenContext.hpp"
#include "Ast/Node.hpp"
#include "Ast/NBlock.hpp"
#include "Ast/NExpression.hpp"
#include "Ast/NStatement.hpp"
#include "Ast/NIdentifier.hpp"
#include "Ast/NVariableDeclaration.hpp"

#include <llvm/Module.h>
#include <llvm/Function.h>
#include <llvm/Type.h>
#include <llvm/DerivedTypes.h>
#include <llvm/LLVMContext.h>
#include <llvm/PassManager.h>
#include <llvm/Instructions.h>
#include <llvm/CallingConv.h>
#include <llvm/Bitcode/ReaderWriter.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/Assembly/PrintModulePass.h>
#include <llvm/Support/IRBuilder.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/JIT.h>
#include <llvm/Support/raw_ostream.h>

#include "parser.gen.hpp"


/* Compile the AST into a module */
void CodeGenContext::generateCode(NBlock& root)
{
	std::cout << "Generating code...\n";

	/* Create the top level interpreter function to call as entry */
	std::vector<Type*> argTypes;
	FunctionType *ftype = FunctionType::get(Type::getVoidTy(getGlobalContext()), argTypes, false);
	mainFunction = Function::Create(ftype, GlobalValue::InternalLinkage, "main", module);
	BasicBlock *bblock = BasicBlock::Create(getGlobalContext(), "entry", mainFunction, 0);

	/* Push a new variable/block context */
	pushBlock(bblock);
	root.codeGen(*this); /* emit bytecode for the toplevel block */
	ReturnInst::Create(getGlobalContext(), bblock);
	popBlock();

	/* Print the bytecode in a human-readable format
	to see if our program compiled properly
	*/
	std::cout << "Code is generated.\n";
	PassManager pm;
	pm.add(createPrintModulePass(&outs()));
	pm.run(*module);
}

/* Executes the AST by running the main function */
GenericValue CodeGenContext::runCode()
{
	std::cout << "Running code...\n";
	ExecutionEngine *ee = EngineBuilder(module).create();
	std::vector<GenericValue> noargs;
	GenericValue v = ee->runFunction(mainFunction, noargs);
	std::cout << "Code was run.\n";
	return v;
}

Type *CodeGenContext::typeOf(const NIdentifier& type)
{
	if (type.name.compare("int") == 0)
	{
		return Type::getInt64Ty(getGlobalContext());
	}
	else if (type.name.compare("double") == 0)
	{
		return Type::getDoubleTy(getGlobalContext());
	}
	return Type::getVoidTy(getGlobalContext());

}

