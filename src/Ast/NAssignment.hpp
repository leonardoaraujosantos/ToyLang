/*
 * class to model assign operations (ie: a = b, z = 10)
 */

#ifndef NASSIGNMENT_HPP_
#define NASSIGNMENT_HPP_

#include "NExpression.hpp"

class NAssignment: public NExpression {
public:
	/*
	 * Left hand side operand
	 */
	NExpression& lhs;

	/*
	 * Right hand side operand
	 */
	NExpression& rhs;

	/*
	 * Constructor ...
	 */
	NAssignment(NExpression& lhs, NExpression& rhs) : lhs(lhs), rhs(rhs) {};

	/*
	 * Override to emmit LLVM IR assign operations
	 */
	//virtual llvm::Value* codeGen(CodeGenContext& context);
};

#endif /* NASSIGNMENT_HPP_ */
