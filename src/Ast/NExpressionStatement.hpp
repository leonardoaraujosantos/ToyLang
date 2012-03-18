/*
 * NExpressionStatement.h
 *
 *  Created on: 18/03/2012
 *      Author: laraujo
 */

#ifndef NEXPRESSIONSTATEMENT_H_
#define NEXPRESSIONSTATEMENT_H_

#include "NStatement.hpp"
#include "NExpression.hpp"

class NExpressionStatement: public NStatement {
public:
	NExpression& expression;
	NExpressionStatement(NExpression& expression) : expression(expression) {};
	//virtual llvm::Value* codeGen(CodeGenContext& context);
};

#endif /* NEXPRESSIONSTATEMENT_H_ */
