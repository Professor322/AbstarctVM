//
// Created by professor on 2/26/21.
//

#include "Token.h"

const std::unordered_map<std::string_view, std::pair<int, eInsns>> InsnToken::insns =  {
	{"add", {0 ,eInsns::ADD} },
	{"sub", {0, eInsns::SUB} },
	{"mul", {0, eInsns::MUL} },
	{"div", {0, eInsns::DIV} },
	{"mod", {0 ,eInsns::MOD} },
	{"push", {1, eInsns::PUSH} },
	{"pop", {0 ,eInsns::POP} },
	{"dump", {0, eInsns::DUMP} },
	{"print", {0, eInsns::PRINT} },
	{"assert", {1, eInsns::ASSERT} },
};

const std::unordered_map<std::string_view, eOperandType> TypeToken::types = {
	{"int8", eOperandType::Int8},
	{"int16", eOperandType::Int16},
	{"int32", eOperandType::Int32},
	{"float", eOperandType::Float},
	{"double", eOperandType::Double}
};

InsnToken::InsnToken(eTokens token, std::string StrInsn) : Token(token), StrInsn(std::move(StrInsn)) {
	const auto it = insns.find(StrInsn);

	if (it != insns.end()) {
		///value->eInsn
		insn = it->second.second;
	}
}

TypeToken::TypeToken(eTokens token, std::string StrType) : Token(token), StrType(std::move(StrType)) {
	const auto it = types.find(StrType);

	if (it != types.end()) {
		///eTypes
		type = it->second;
	}
}
