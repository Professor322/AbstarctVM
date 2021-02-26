//
// Created by professor on 2/23/21.
//

#ifndef ABSTARCTVM_ENGINE_H
#define ABSTARCTVM_ENGINE_H

#include "OperandDerived.h"
#include "Stack.h"
#include "Token.h"
#include <list>
#include <unordered_map>
#include <fstream>



class Engine {
	std::list<std::unique_ptr<Token>> tokens;

	std::unique_ptr<Token> getToken(std::istream& it);
public:
	std::list<std::unique_ptr<Token>> Tokenize(std::istream& it);

	void Run() {

	}
};


#endif //ABSTARCTVM_ENGINE_H
