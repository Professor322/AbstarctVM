//
// Created by professor on 2/23/21.
//

#include "Stack.h"
#include <iostream>

std::pair<std::shared_ptr<const IOperand>, std::shared_ptr<const IOperand>> Stack::PrepareOperands() {
	auto op1 = list.front(); list.pop_front();
	auto op2 = list.front(); list.pop_front();
	return {op1, op2};
}
void Stack::Add()
{
	auto [op1, op2] = PrepareOperands();

	list.push_front(std::shared_ptr<const IOperand>{*op1.get() + *op2.get()});
}

void Stack::Assert(std::shared_ptr<const IOperand> op)
{}

void Stack::Div()
{
	auto [op1, op2] = PrepareOperands();
	list.push_front(std::shared_ptr<const IOperand>{*op1.get() / *op2.get()});
}

void Stack::Dump()
{
	for (const auto& elem : list) {
		std::cout << elem->toString() << '\n';
	}
}

void Stack::Mod()
{

	auto [op1, op2] = PrepareOperands();

	list.push_front(std::shared_ptr<const IOperand>{*op1.get() % *op2.get()});
}

void Stack::Mul()
{
	auto [op1, op2] = PrepareOperands();
	list.push_front(std::shared_ptr<const IOperand>{*op1.get() * *op2.get()});
}

void Stack::Pop()
{
	list.pop_front();
}

void Stack::Print()
{

}

void Stack::Push(std::shared_ptr<const IOperand> op)
{
	list.push_front(op);
}

void Stack::Sub()
{

	auto [op1, op2] = PrepareOperands();

	list.push_front(std::shared_ptr<const IOperand>{*op1.get() - *op2.get()});
}

void Stack::Exit() {

	exit(0);
}