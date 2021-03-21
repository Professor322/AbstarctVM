//
// Created by professor on 2/23/21.
//

#include "Engine.h"
//todo add looking for ';;' from input
//todo add line counter mb?
std::shared_ptr<Token> Engine::getToken(std::istream& fs) {
	static char LastChar = ' ';

	if (fs.eof())
		return std::make_shared<SymbolToken>(eTokens::END);


	while (!fs.eof() && isspace(LastChar) && LastChar != '\n')
		fs.get(LastChar);
	if (LastChar == ';') {
		if (fs.peek() == ';')
			return std::make_shared<SymbolToken>(eTokens::END);
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
		///unknown token
		return std::make_shared<SymbolToken>(eTokens::UNKNOWN, Identifier);
	}

	fs.get(LastChar);
	return std::make_shared<SymbolToken>(eTokens::UNKNOWN, LastChar);
}

std::list<std::shared_ptr<Token>> Engine::Tokenize(std::istream &it) {
	do {
		tokens.push_back(getToken(it));
	}
	while (tokens.back()->getBaseToken() != eTokens::END);

	return tokens;
}


void Engine::checkUnknown() {
	for (const auto& token : tokens) {
		switch(token->getBaseToken()) {
			default: break;
			case eTokens::INSN: {
				auto InsnName = static_cast<eInsns>(token->getSpecificToken());
				if (InsnName == eInsns::UNKNOWN_INSN)
					EH.addError("Unknown instruction: " + token->getStrValue());
				break;
			}
			case eTokens::VALUE_TYPE: {
				auto ValueType = static_cast<eOperandType>(token->getSpecificToken());
				if (ValueType == eOperandType::UnknownType)
					EH.addError("Unknown type: " + token->getStrValue());
				break;
			}
			case eTokens::UNKNOWN:
				EH.addError("Unknown token: " + token->getStrValue());
				break;
		}
	}
}

void Engine::checkBrackets() {
	std::stack<eTokens> brackets;
	for (const auto& token : tokens) {
		if (token->getBaseToken() == eTokens::OPEN_BRACKET) {
			brackets.push(eTokens::OPEN_BRACKET);
		} else if (token->getBaseToken() == eTokens::CLOSE_BRACKET) {
			if (brackets.empty()) {
				EH.addError("Not matched bracket: )");
				return ;
			}
			brackets.pop();
		}
	}

	if (!brackets.empty()) {
		EH.addError("Not matched bracket: (");
	}

}

void Engine::checkInsnArgs() {
	const static std::unordered_map<eInsns, size_t> ArgNum {
			{ eInsns::ADD, 0},
			{ eInsns::SUB, 0},
			{ eInsns::MUL, 0},
			{ eInsns::DIV, 0},
			{ eInsns::MOD, 0},
			{ eInsns::PUSH,1},
			{ eInsns::POP, 0},
			{ eInsns::DUMP, 0},
			{ eInsns::PRINT, 0},
			{ eInsns::ASSERT,1},
			{ eInsns::EXIT, 0},
	};

	for (auto it = tokens.begin(); it != tokens.end(); ) {
		if (it->get()->getBaseToken() == eTokens::INSN) {
			auto InsnToken = static_cast<eInsns>(it->get()->getSpecificToken());
			if (!ArgNum.contains(InsnToken)) {
				EH.addError("Do not know arg num for unknown instruction: " + it->get()->getStrValue());
				++it;
				continue;
			}
			///because there are only two cases: 0, 1
			if (ArgNum.at(InsnToken) == 0) {
				///means that next token should be {END, NEWLINE}
				if (++it != tokens.end()) {
					eTokens CurToken = it->get()->getBaseToken();
					if (CurToken != eTokens::END && CurToken != eTokens::NEW_LINE) {
						EH.addError("Instruction " + it->get()->getStrValue() + " takes 0 arguments");
					}
				}
			} else {
				auto InsnTokenIt = it;
				//means that next tokens should be VALUE TYPE, VALUE, {END, NEW_LINE}
				if (next(it) != tokens.end() &&
				   (++it)->get()->getBaseToken() != eTokens::VALUE_TYPE) {
					EH.addError("For instruction " + InsnTokenIt->get()->getStrValue() + " no value type supplied");
				}
				if (next(it) != tokens.end() &&
				   (++it)->get()->getBaseToken() != eTokens::VALUE) {
					EH.addError("For instruction " + InsnTokenIt->get()->getStrValue() + " no value supplied");
				}

				if (next(it) != tokens.end() &&
				   ((++it)->get()->getBaseToken() != eTokens::NEW_LINE &&
				   it->get()->getBaseToken() != eTokens::END )) {
					EH.addError("Instruction " + InsnTokenIt->get()->getStrValue() + " takes 1 argument");
				}
			}
		}
		++it;
	}
}

void Engine::checkInsnPerLine() {
	///one instruction per line, every line starts with instruction
	///if PrevToken == NEWLINE than CurToken == INSN
	///also check for exit at the end
	size_t InsnPerLineCounter = 0;
	eTokens PrevToken = eTokens::NEW_LINE;

	for (const auto& token : tokens) {
		auto CurToken = token->getBaseToken();
		if (CurToken == eTokens::INSN) {
			InsnPerLineCounter++;
		} else if (CurToken == eTokens::NEW_LINE || CurToken == eTokens::END) {
			if (InsnPerLineCounter != 1)
				EH.addError("Every line of code should have only 1 instruction");
			InsnPerLineCounter = 0;
		}

		if ((PrevToken == eTokens::NEW_LINE || PrevToken == eTokens::END) &&
			CurToken != eTokens::INSN) {
			EH.addError("Every line of code should start with an instruction");
		}

		PrevToken = CurToken;
	}

	//todo find out if exit can be placed in the middle of the code
	auto ExitCheck = next(tokens.rbegin());
	auto InsnToken = static_cast<eInsns>(ExitCheck->get()->getSpecificToken());
	if (InsnToken != eInsns::EXIT) {
		EH.addError("No 'exit' instruction at the end");
	}
}

void Engine::checkGrammar() {
	checkUnknown();
	checkBrackets();

	tokens.remove_if([](const std::shared_ptr<Token> token) {
		return token->getBaseToken() == eTokens::CLOSE_BRACKET ||
			   token->getBaseToken() == eTokens::OPEN_BRACKET;
	});

	checkInsnArgs();
	checkInsnPerLine();

	if (EH.getErrorCounter()) {
		throw EH;
	}
	tokens.remove_if([](const std::shared_ptr<Token> token) {
		return  token->getBaseToken() == eTokens::NEW_LINE ||
				token->getBaseToken() == eTokens::UNKNOWN ||
				token->getBaseToken() == eTokens::END;

	});

}

///todo will be eliminated perhaps

auto Engine::createOperand(Token *typeToken, Token *valueToken)   {
	auto type = static_cast<eOperandType>(typeToken->getSpecificToken());
	auto value = valueToken->getStrValue();
	return std::shared_ptr<const IOperand>{oc.createOperand(type, value)};
}

///todo think of the ways hot to eliminate this crazy switch case, maybe it is not necessary
void Engine::Execute() {

	auto it = tokens.begin();

	while (it != tokens.end()) {
		///tokens should start with insn
		auto insn = static_cast<eInsns>(it->get()->getSpecificToken());
		switch(insn) {
			///todo maybe create an array of function pointers in Stack class to call an insn
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
				Token *type = (++it)->get();
				Token *value = (++it)->get();
				stack.Push(createOperand(type, value));
				break;
			}
			case eInsns::ASSERT: {
				Token *type = (++it)->get();
				Token *value = (++it)->get();
				stack.Assert(createOperand(type, value));
				break;
			}
		}
		it++;

	}
}