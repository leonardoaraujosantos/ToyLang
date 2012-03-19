/*
 * Ast class to model block of code (declaration, method calls, expressions, etc...)
 */

#ifndef NBLOCK_HPP_
#define NBLOCK_HPP_

#include "NExpression.hpp"
#include "NStatement.hpp"

#include "../CodeGenContext.hpp"

class NBlock: public NExpression {
public:
	/*
	 * List of statements (declaration, method calls, expressions, etc...)
	 */
	std::vector<NStatement*> statements;

	/*
	 * Constructor ... (Called by the grammar parsing...)
	 */
	NBlock() {};

	/*
	 * Overrided to emit proper LLVM IR code.
	 */
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

#endif /* NBLOCK_HPP_ */
