//
// Created by professor on 2/23/21.
//

#ifndef ABSTARCTVM_OPERANDDERIVED_H
#define ABSTARCTVM_OPERANDDERIVED_H

#include "IOperand.h"

using Types = std::variant<int8_t , int16_t , int32_t, float, double>;

Types getVariant(eOperandType type, const std::string& strVal);

class Operand : public IOperand {
private:
	const std::string Value;
	const eOperandType type;
	OperandCreator oc;


	[[nodiscard]] std::tuple<eOperandType, Types, Types> ops_for_arith(IOperand const &rhs) const;
public:
	explicit Operand(const std::string&  Value, const eOperandType type);

	[[nodiscard]] int getPrecision() const override { return static_cast<int>(type); } // Precision of the type of the instance
	[[nodiscard]] eOperandType getType() const override { return type; } // Type of the instance
	[[nodiscard]] std::string const &toString() const override { return Value; }

	///actual values are forming when we decided which type of value will it be
	IOperand const *operator+(IOperand const &rhs) const override; //Sum
	IOperand const *operator-(IOperand const &rhs) const override; // Difference
	IOperand const *operator*(IOperand const &rhs) const override; // Product
	IOperand const *operator/(IOperand const &rhs) const override; // Quotient
	IOperand const *operator%(IOperand const &rhs) const override; // Modulo

};

#endif //ABSTARCTVM_OPERANDDERIVED_H
