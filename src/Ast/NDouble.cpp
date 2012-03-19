/*
 * NDouble.cpp
 *
 *  Created on: 18/03/2012
 *      Author: laraujo
 */
#include "NDouble.hpp"

Value* NDouble::codeGen(CodeGenContext& context)
{
	std::cout << "Creating double: " << value << std::endl;
	return ConstantFP::get(Type::getDoubleTy(getGlobalContext()), value);
}
