//
// Created by professor on 2/23/21.
//
#include "IOperand.h"
#include <iostream>

int main() {
	OperandCreator oc;
	const IOperand *op1 = oc.createOperand(eOperandType::Float, "178.4");
	const IOperand *op2 = oc.createOperand(eOperandType::Int8, "14");

	const IOperand *result = *op1 + *op2;
	std::cout << result->toString() << " " << static_cast<int>(result->getType());
	return 0;
}