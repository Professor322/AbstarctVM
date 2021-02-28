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
	EXIT
};

class Token {
	eTokens token;
public:
	[[nodiscard]] eTokens getBaseToken() const { return token; }
	[[nodiscard]] virtual unsigned int getSpecificToken() const { return -1; }
	[[nodiscard]] virtual std::string getStrValue() const = 0;
	Token(eTokens token) : token(token) {}
};

class InsnToken : public Token {
	eInsns insn;
	const std::string StrInsn;
	static const std::unordered_map<std::string, std::pair<int, eInsns>> insns;
public:
	InsnToken(eTokens token, std::string StrInsn);
	[[nodiscard]] unsigned int getSpecificToken() const override { return static_cast<int>(insn); }
	[[nodiscard]] std::string getStrValue() const override { return StrInsn; }
};

class TypeToken : public Token {
	eOperandType type;
	std::string StrType;
	static const std::unordered_map<std::string, eOperandType> types;
public:
	TypeToken(eTokens token, std::string StrInsn);
	[[nodiscard]] unsigned int getSpecificToken() const override {return static_cast<int>(type);}
	[[nodiscard]] std::string getStrValue() const override { return StrType; }

};

class ValueToken : public Token {
	std::string StrValue;
public:
	ValueToken(eTokens token, std::string StrValue) : Token(token), StrValue(std::move(StrValue)) {}
	[[nodiscard]] std::string getStrValue() const override { return StrValue; }

};

class SymbolToken : public Token {
	char BasicChar;
public:
	SymbolToken(eTokens token, char BasicChar) : Token(token), BasicChar(BasicChar) {}
	SymbolToken(eTokens token) : Token(token) {}
	[[nodiscard]] std::string getStrValue() const override { return std::string{BasicChar}; }

};
#endif //ABSTARCTVM_TOKEN_H
