/*
 * class to model normal identifier in our language
 */

#ifndef NIDENTIFIER_HPP_
#define NIDENTIFIER_HPP_

#include "NExpression.hpp"
class NIdentifier : public NExpression
{
public:

	/*
	 * Will retain the value of our floating point expression
	 */
	std::string name;

	/*
	 * Constructor (wich will initialize our value variable)
	 */
	NIdentifier (const std::string& value) : name(name){};

	/*
	 * We will override the codeGen method to emit valid LLVM IR code for identifiers
	 * declaration. (Can be variables, types, method names etc...)
	 */
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

#endif /* NIDENTIFIER_HPP_ */
