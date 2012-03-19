/*
 * NInteger.cpp
 *
 *  Created on: 18/03/2012
 *      Author: laraujo
 */
#include "NInteger.hpp"

Value* NInteger::codeGen(CodeGenContext& context)
{
	std::cout << "Creating integer: " << value << std::endl;
	return ConstantInt::get(Type::getInt64Ty(getGlobalContext()), value, true);
}
