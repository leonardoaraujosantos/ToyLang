/*
 * Any floating point expression
 */

#ifndef NDOUBLE_HPP_
#define NDOUBLE_HPP_

#include "NExpression.hpp"

class NDouble : public NExpression
{
public:

	/*
	 * Will retain the value of our floating point expression
	 */
	double value;

	/*
	 * Constructor (wich will initialize our value variable)
	 */
	NDouble (double value) : value(value){};

	/*
	 * We will override the codeGen method to emit valid LLVM IR code for float variable
	 * declaration.
	 */
	//virtual llvm::Value* codeGen(CodeGenContext& context);
};


#endif /* NDOUBLE_HPP_ */
