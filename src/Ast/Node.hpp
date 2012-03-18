/*
 * Top node of our Ast tree, the ast tree must model all of our grammar
 */

#ifndef NODE_HPP_
#define NODE_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <llvm/Value.h>

class Node
{
	virtual ~Node() {};

	/*
	 * A virtual method indicate that it's behavior can change in inherited classes.
	 * more information refer: http://en.wikipedia.org/wiki/Virtual_function
	 * The method codeGen will be used to emit LLVM IR code...
	 */
	virtual llvm::Value * codeGen(CodeGenContext& context) { };
};

#endif /* NODE_HPP_ */

