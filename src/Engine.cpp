//
// Created by professor on 2/23/21.
//

#include "Engine.h"

std::unique_ptr<Token> Engine::getToken(std::istream& fs) {
	static char LastChar = ' ';

	if (fs.eof())
		return std::make_unique<BasicToken>(eTokens::END);


	while (!fs.eof() && isspace(LastChar) && LastChar != '\n')
		fs.get(LastChar);
	if (LastChar == ';') {
		while (!fs.eof() && LastChar != '\n')
			fs.get(LastChar);
		return getToken(fs.get(LastChar));
	}

	if (LastChar == '\n') {
		fs.get(LastChar);
		return std::make_unique<BasicToken>(eTokens::NEW_LINE);
	}
	if (LastChar == '(') {
		fs.get(LastChar);
		return std::make_unique<BasicToken>(eTokens::OPEN_BRACKET);
	}
	if (isdigit(LastChar)) {
		std::string Value;
		while (!fs.eof() && isdigit(LastChar) || LastChar == '.') {
			Value += LastChar;
			fs.get(LastChar);
		}
		return std::make_unique<ValueToken>(eTokens::VALUE, Value);

	}
	if (LastChar == ')') {
		fs.get(LastChar);
		return std::make_unique<BasicToken>(eTokens::CLOSE_BRACKET);
	}


	if (isalpha(LastChar)) {
		std::string Identifier;

		while (!fs.eof() && isalnum(LastChar)) {
			Identifier += LastChar;
			fs.get(LastChar);
		}
		///if next symbol isspace that means we have parse an instruction
		if (fs.eof() || isspace(LastChar))
			return std::make_unique<InsnToken>(eTokens::INSN, Identifier);
		///that means we have tokenized VALUE TYPE
		if (LastChar == '(')
			return std::make_unique<TypeToken>(eTokens::VALUE_TYPE, Identifier);

	}

	fs.get(LastChar);
	return std::make_unique<BasicToken>(eTokens::UNKNOWN, LastChar);
}

std::list<std::unique_ptr<Token>> Engine::Tokenize(std::istream &it) {
	do
		tokens.push_back(getToken(it));
	while (tokens.back()->getToken() != eTokens::END);

	return tokens;
}