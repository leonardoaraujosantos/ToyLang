/*
 * Ast Class to model variable declaration (with or without assingment)
 * ie: int x = 0
 *     int x
 */

#ifndef NVARIABLEDECLARATION_HPP_
#define NVARIABLEDECLARATION_HPP_

#include "NStatement.hpp"

class NVariableDeclaration: public NStatement {
public:
	/*
	 * Will hold the type of the variable declaration (integer or double)
	 */
	const NIdentifier& type;

	/*
	 * Will hold the variable name
	 */
	NIdentifier& id;

	/*
	 * Optional assign when declaring variables
	 */
	NExpression *assignmentExpr;

	/*
	 * Constructor called by the grammar parser on the case of simple variable declaration
	 */
	NVariableDeclaration(const NIdentifier& type, NIdentifier& id) : type(type), id(id) {};

	/*
	 * Constructor called by the grammar parser on the case of variable declaration with assign
	 */
	NVariableDeclaration(const NIdentifier& type, NIdentifier& id, NExpression *assignmentExpr) :
		type(type), id(id), assignmentExpr(assignmentExpr) { };

	/*
	 * Emit LLVM IR variable declaration
	 */
	//virtual llvm::Value* codeGen(CodeGenContext& context);
};

#endif /* NVARIABLEDECLARATION_HPP_ */
