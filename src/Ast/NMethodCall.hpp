/*
 * Normal method call with our without arguments
 */

#ifndef NMETHODCALL_HPP_
#define NMETHODCALL_HPP_

#include "NExpression.hpp"
#include "NIdentifier.hpp"

#include "../CodeGenContext.hpp"

class NMethodCall : public NExpression
{
public:
	/*
	 * name of the method
	 */
	const NIdentifier &id;

	/*
	 * List of arguments
	 */
	std::vector<NExpression*> arguments;

	/*
	 * Constructor when we got arguments
	 */
	NMethodCall(const NIdentifier &id, std::vector<NExpression*>& arguments) : id(id), arguments(arguments) {};

	/*
	 * Constructor when we don't have any arguments
	 */
	NMethodCall(const NIdentifier &id) : id(id) {};

	/*
	 *	We will override the codeGen to emmit LLVM IR to call some method
	 */
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

#endif /* NMETHODCALL_HPP_ */
