//
// Created by professor on 2/23/21.
//

#include "OperandDerived.h"


Types getVariant(const eOperandType type, const std::string& strVal) {
	switch(type) {
		case eOperandType::Int8:
			return static_cast<char>(std::stoi(strVal));
		case eOperandType::Int16:
			return static_cast<short>(std::stoi(strVal));
		case eOperandType::Int32:
			return std::stoi(strVal);
		case eOperandType::Float:
			return std::stof(strVal);
		case eOperandType::Double:
			return std::stod(strVal);
	}
	//to make compiler happy
	return 0;
}

