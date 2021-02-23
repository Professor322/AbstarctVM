//
// Created by professor on 2/23/21.
//

#ifndef ABSTARCTVM_STACK_H
#define ABSTARCTVM_STACK_H

#include <OperandDerived.h>
#include <memory>
#include <stack>

class MyStack {
private:
	std::stack<std::shared_ptr<const IOperand*>> st;
public:
};


#endif //ABSTARCTVM_STACK_H
