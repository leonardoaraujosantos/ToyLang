/*
 * NBinaryOperator.cpp
 *
 *  Created on: 18/03/2012
 *      Author: laraujo
 */

#include "NBinaryOperator.hpp"
#include "NStatement.hpp"
#include "NVariableDeclaration.hpp"
#include "../parser.gen.hpp"

Value* NBinaryOperator::codeGen(CodeGenContext& context)
{
	std::cout << "Creating binary operation " << op << std::endl;
	llvm::Instruction::BinaryOps instr;

	switch (op)
	{
		case TPLUS: instr = llvm::Instruction::Add; goto math;
		case TMINUS: instr = llvm::Instruction::Sub; goto math;
		case TMUL: instr = llvm::Instruction::Mul; goto math;
		case TDIV: instr = llvm::Instruction::SDiv; goto math;

		/* TODO comparison */
	}

	return NULL;
	math:
		return llvm::BinaryOperator::Create(instr, lhs.codeGen(context),rhs.codeGen(context), "", context.currentBlock());
}


