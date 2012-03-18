/*
 * Ast class to model function declaration
 * ie:
   int do_math(int a) {
	  int x = a * 5 + 3
   }
 */

#ifndef NFUNCTIONDECLARATION_HPP_
#define NFUNCTIONDECLARATION_HPP_

#include "NStatement.hpp"

class NFunctionDeclaration: public NStatement {
public:
	const NIdentifier& type;

	const NIdentifier& id;

	std::vector<NVariableDeclaration*> arguments;

	NBlock& block;
	NFunctionDeclaration(const NIdentifier& type, const NIdentifier& id, const std::vector<NVariableDeclaration*>& arguments, NBlock& block) :
		type(type), id(id), arguments(arguments), block(block) {};

	virtual llvm::Value* codeGen(CodeGenContext& context);
};

#endif /* NFUNCTIONDECLARATION_HPP_ */
