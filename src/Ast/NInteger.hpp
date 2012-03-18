/*
 * Any integer expression
 */

#ifndef NINTEGER_HPP_
#define NINTEGER_HPP_

#include "NExpression.hpp"

class NInteger : public NExpression
{
public:

	/*
	 * Will retain the value of our integer expression
	 */
	long long value;

	/*
	 * Constructor (wich will initialize our value variable)
	 */
	NInteger (long long value) : value(value){};

	/*
	 * We will override the codeGen method to emit valid LLVM IR code for integer variable
	 * declaration.
	 */
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

#endif /* NINTEGER_HPP_ */
