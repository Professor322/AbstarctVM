//
// Created by professor on 2/23/21.
//

#ifndef ABSTARCTVM_ENGINE_H
#define ABSTARCTVM_ENGINE_H

#include "OperandDerived.h"
#include "Stack.h"
#include <vector>
#include <unordered_map>
#include <fstream>

enum class eTokens {
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	PUSH,
	POP,
	DUMP,
	PRINT,
	ASSERT,
	VALUE_TYPE,
	OPEN_BRACKET,
	VALUE,
	CLOSE_BRACKET,
	COMMENT,
	NEW_LINE,
	END,
};

struct Token {
	eTokens token;
	std::string val;
};

class Engine {
	std::vector<Token> tokens;
	const std::unordered_map<std::string, eTokens> dict {
		{"add", eTokens::ADD},
		{"sub", eTokens::SUB},
		{"mul", eTokens::MUL},
		{"div", eTokens::DIV},
		{"mod", eTokens::MOD},
		{"push", eTokens::PUSH},
		{"pop", eTokens::POP},
		{"dump", eTokens::DUMP},
		{"print", eTokens::PRINT},
		{"assert", eTokens::ASSERT},
	};

public:
	std::vector<Token> Tokenize(std::fstream& it);

	void Run() {

	}
};


#endif //ABSTARCTVM_ENGINE_H
