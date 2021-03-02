//
// Created by professor on 2/23/21.
//

#ifndef ABSTARCTVM_STACK_H
#define ABSTARCTVM_STACK_H

#include <OperandDerived.h>
#include <memory>
#include <list>

class Stack {
private:
	std::list<std::shared_ptr<const IOperand>> list;
	std::pair<std::shared_ptr<const IOperand>, std::shared_ptr<const IOperand>> PrepareOperands();
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
	void Exit();
};


#endif //ABSTARCTVM_STACK_H
