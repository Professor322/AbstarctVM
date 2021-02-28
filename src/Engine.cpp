//
// Created by professor on 2/23/21.
//

#include "Engine.h"

std::shared_ptr<Token> Engine::getToken(std::istream& fs) {
	static char LastChar = ' ';

	if (fs.eof())
		return std::make_shared<SymbolToken>(eTokens::END);


	while (!fs.eof() && isspace(LastChar) && LastChar != '\n')
		fs.get(LastChar);
	if (LastChar == ';') {
		while (!fs.eof() && LastChar != '\n')
			fs.get(LastChar);
		return getToken(fs.get(LastChar));
	}

	if (LastChar == '\n') {
		fs.get(LastChar);
		return std::make_shared<SymbolToken>(eTokens::NEW_LINE);
	}

	if (LastChar == '(') {
		fs.get(LastChar);
		return std::make_shared<SymbolToken>(eTokens::OPEN_BRACKET);
	}

	if (isdigit(LastChar)) {
		std::string Value;
		while (!fs.eof() && isdigit(LastChar) || LastChar == '.') {
			Value += LastChar;
			fs.get(LastChar);
		}
		return std::make_shared<ValueToken>(eTokens::VALUE, Value);

	}
	if (LastChar == ')') {
		fs.get(LastChar);
		return std::make_shared<SymbolToken>(eTokens::CLOSE_BRACKET);
	}


	if (isalpha(LastChar)) {
		std::string Identifier;

		while (!fs.eof() && isalnum(LastChar)) {
			Identifier += LastChar;
			fs.get(LastChar);
		}
		///if next symbol isspace that means we have parse an instruction
		if (fs.eof() || isspace(LastChar))
			return std::make_shared<InsnToken>(eTokens::INSN, Identifier);
		///that means we have tokenized VALUE TYPE
		if (LastChar == '(')
			return std::make_shared<TypeToken>(eTokens::VALUE_TYPE, Identifier);

	}

	fs.get(LastChar);
	return std::make_shared<SymbolToken>(eTokens::UNKNOWN, LastChar);
}

std::list<std::shared_ptr<Token>> Engine::Tokenize(std::istream &it) {
	do
		tokens.push_back(getToken(it));
	while (tokens.back()->getBaseToken() != eTokens::END);

	return tokens;
}

void Engine::checkGrammar() {

	tokens.remove_if([](const std::shared_ptr<Token> token) {
		return token->getBaseToken() == eTokens::CLOSE_BRACKET ||
				token->getBaseToken() == eTokens::OPEN_BRACKET ||
				token->getBaseToken() == eTokens::NEW_LINE ||
				token->getBaseToken() == eTokens::UNKNOWN ||
				token->getBaseToken() == eTokens::END;

	});

	///check parenthess delete paranthes
	///check number of instruction per line //delete newlines
}

auto Engine::createOperand(Token *typeToken, Token *valueToken)   {
	auto type = static_cast<eOperandType>(typeToken->getSpecificToken());
	auto value = valueToken->getStrValue();
	return std::shared_ptr<const IOperand>{oc.createOperand(type, value)};
}

void Engine::Execute() {
	auto it = tokens.begin();

	while (it != tokens.end()) {
		///tokens should start with insn
		auto insn = static_cast<eInsns>(it->get()->getSpecificToken());
		switch(insn) {
			case eInsns::ADD:
				stack.Add();
				break;
			case eInsns::SUB:
				stack.Sub();
				break;
			case eInsns::MUL:
				stack.Mul();
				break;
			case eInsns::DIV:
				stack.Div();
				break;
			case eInsns::MOD:
				stack.Mod();
				break;
			case eInsns::POP:
				stack.Pop();
				break;
			case eInsns::DUMP:
				stack.Dump();
				break;
			case eInsns::PRINT:
				stack.Print();
				break;
			case eInsns::EXIT:
				stack.Exit();
				break;
			case eInsns::PUSH: {
				auto type = (++it)->get();
				auto value = (++it)->get();
				stack.Push(createOperand(type, value));
				break;
			}
			case eInsns::ASSERT: {
				auto type = (++it)->get();
				auto value = (++it)->get();
				stack.Assert(createOperand(type, value));
				break;
			}
		}
		it++;

	}
}