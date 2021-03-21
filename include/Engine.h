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
#include <stack>
#include "ErrorHandler.h"


class Engine {
	std::list<std::shared_ptr<Token>> tokens;
	Stack stack;
	OperandCreator oc;
	ErrorHandler EH;
	std::shared_ptr<Token> getToken(std::istream& it);
	auto createOperand(Token *typeToken, Token *valueToken);
	void checkUnknown();
	void checkBrackets();
	void checkInsnPerLine();
	void checkInsnArgs();


public:
	std::list<std::shared_ptr<Token>> Tokenize(std::istream& it);
	void checkGrammar();
	void Execute();
};


#endif //ABSTARCTVM_ENGINE_H
