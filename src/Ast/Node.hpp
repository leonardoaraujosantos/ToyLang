/*
 * Top node of our Ast tree, the ast tree must model all of our grammar
 */

#ifndef NODE_HPP_
#define NODE_HPP_

#include <iostream>
#include <vector>
#include <string>

/*#include "NAssignment.hpp"
#include "NBinaryOperator.hpp"
#include "NBlock.hpp"
#include "NDouble.hpp"
#include "NExpression.hpp"
#include "NExpressionStatement.hpp"
#include "NFunctionDeclaration.hpp"
#include "NIdentifier.hpp"
#include "NInteger.hpp"
#include "NMethodCall.hpp"
#include "NStatement.hpp"
#include "NVariableDeclaration.hpp"*/


#include "../CodeGenContext.hpp"


class Node
{
public:
	virtual ~Node() {};

	/*
	 * A virtual method indicate that it's behavior can change in inherited classes.
	 * more information refer: http://en.wikipedia.org/wiki/Virtual_function
	 * The method codeGen will be used to emit LLVM IR code...
	 */
	virtual llvm::Value *codeGen(CodeGenContext& context) {};

};

#endif /* NODE_HPP_ */

