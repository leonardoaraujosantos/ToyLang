/*
 * NBinaryOperator.hpp
 *
 *  Created on: 18/03/2012
 *      Author: laraujo
 */

#ifndef NBINARYOPERATOR_HPP_
#define NBINARYOPERATOR_HPP_

#include "NExpression.hpp"
#include "../CodeGenContext.hpp"


class NBinaryOperator: public NExpression {
public:
	/*
	 * Type of the operator
	 */
	int op;

	/*
	 * Left hand side operand
	 */
	NExpression& lhs;

	/*
	 * Right hand side operand
	 */
	NExpression& rhs;

	/*
	 * Constructor...
	 */
	NBinaryOperator(NExpression& lhs, int op, NExpression& rhs) : lhs(lhs), rhs(rhs), op(op) {};

	/*
	 * Override to emmit LLVM IR operations
	 */
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

#endif /* NBINARYOPERATOR_HPP_ */
