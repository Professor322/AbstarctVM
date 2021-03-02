//
// Created by professor on 2/23/21.
//
#include "IOperand.h"
#include "Engine.h"
#include <iostream>

int main(int argc, char** argv) {
	Engine e;
	std::fstream f(argv[1]);

	e.Tokenize(std::cin);
	e.checkGrammar();
	e.Execute();

	f.close();
	return 0;
}