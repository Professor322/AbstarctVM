//
// Created by professor on 2/26/21.
//

#ifndef ABSTARCTVM_TOKEN_H
#define ABSTARCTVM_TOKEN_H

#include <unordered_map>
#include "IOperand.h"

enum class eTokens {
	INSN,
	VALUE_TYPE,
	OPEN_BRACKET,
	VALUE,
	CLOSE_BRACKET,
	NEW_LINE,
	END,
	UNKNOWN
};

enum class eInsns {
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
};

class Token {
	eTokens token;
public:
	[[nodiscard]] eTokens getToken() const { return token; }

	Token(eTokens token) : token(token) {}
};

class InsnToken : public Token {
	eInsns insn;
	const std::string StrInsn;
	static const std::unordered_map<std::string_view, std::pair<int, eInsns>> insns;
public:
	InsnToken(eTokens token, std::string StrInsn);
};

class TypeToken : public Token {
	eOperandType type;
	std::string StrType;
	static const std::unordered_map<std::string_view, eOperandType> types;
public:
	TypeToken(eTokens token, std::string StrInsn);

};

class ValueToken : public Token {
	std::string StrValue;
public:
	ValueToken(eTokens token, std::string StrValue) : Token(token), StrValue(std::move(StrValue)) {}
};

class BasicToken : public Token {
	char BasicChar;
public:
	BasicToken(eTokens token, char BasicChar) : Token(token), BasicChar(BasicChar) {}
	BasicToken(eTokens token) : Token(token) {}
};
#endif //ABSTARCTVM_TOKEN_H
