//
// Created by professor on 2/23/21.
//

#include "Engine.h"

Token Engine::getToken(std::istream& fs) {
	static char LastChar = ' ';
	//skip spaces

	if (fs.eof())
		return {eTokens::END, std::string{}};


	while (!fs.eof() && isspace(LastChar) && LastChar != '\n')
		fs.get(LastChar);
	if (LastChar == ';') {
		while (!fs.eof() && LastChar != '\n')
			fs.get(LastChar);
		return getToken(fs.get(LastChar));
	}

	if (LastChar == '\n') {
		fs.get(LastChar);
		return {eTokens::NEW_LINE, std::string{}};
	}
	if (LastChar == '(') {
		fs.get(LastChar);
		return {eTokens::OPEN_BRACKET, std::string{}};
	}
	if (isdigit(LastChar)) {
		std::string Value;
		while (!fs.eof() && isdigit(LastChar) || LastChar == '.') {
			Value += LastChar;
			fs.get(LastChar);
		}
		return {eTokens::VALUE, std::move(Value)};

	}
	if (LastChar == ')') {
		fs.get(LastChar);
		return {eTokens::CLOSE_BRACKET, std::string{}};
	}


	if (isalpha(LastChar)) {
		std::string Identifier;

		while (!fs.eof() && isalnum(LastChar)) {
			Identifier += LastChar;
			fs.get(LastChar);
		}
		///if next symbol isspace that means we have parse an instruction
		if (fs.eof() || isspace(LastChar))
			return {eTokens::INSN, std::move(Identifier)};
		///that means we have tokenized VALUE TYPE
		if (LastChar == '(')
			return {eTokens::VALUE_TYPE, std::move(Identifier)};

	}

	fs.get(LastChar);
	return {eTokens::UNKNOWN, std::string{}};
}

std::list<Token> Engine::Tokenize(std::istream &it) {
	do {
		tokens.push_back(getToken(it));
	}
	while (tokens.back().token != eTokens::END);

	return tokens;
}