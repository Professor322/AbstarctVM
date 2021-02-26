//
// Created by professor on 2/23/21.
//

#ifndef ABSTARCTVM_STACK_H
#define ABSTARCTVM_STACK_H

#include <OperandDerived.h>
#include <memory>
#include <stack>

class Stack {
private:
	std::stack<std::shared_ptr<const IOperand>> st;
public:
	void Add();
	void Sub();
	void Mul();
	void Div();
	void Mod();
	void Push(std::shared_ptr<const IOperand> op);
	void Pop();
	void Dump();
	void Print();
	void Assert(std::shared_ptr<const IOperand> op);
};


#endif //ABSTARCTVM_STACK_H
