//
// Created by professor on 2/23/21.
//

#include "OperandDerived.h"

Operand::Operand(const std::string &Value, const eOperandType type) : Value(Value), type(type), oc() {}

[[nodiscard]] std::tuple<eOperandType, Types, Types> Operand::ops_for_arith(IOperand const &rhs) const {
	eOperandType opType = getPrecision() < getPrecision() ? rhs.getType() : getType();
	return {opType, getVariant(opType, toString()), getVariant(opType, rhs.toString())};
}

IOperand const * Operand::operator+(const IOperand &rhs) const
{
	const auto [opType, lhs_val, rhs_val] = ops_for_arith(rhs);

	switch(opType) {
		case eOperandType::Int8:
			return oc.createOperand(opType,std::to_string(std::get<0>(lhs_val) + std::get<0>(rhs_val)));
		case eOperandType::Int16:
			return oc.createOperand(opType,std::to_string(std::get<1>(lhs_val) + std::get<1>(rhs_val)));
		case eOperandType::Int32:
			return oc.createOperand(opType,std::to_string(std::get<2>(lhs_val) + std::get<2>(rhs_val)));
		case eOperandType::Float:
			return oc.createOperand(opType,std::to_string(std::get<3>(lhs_val) + std::get<3>(rhs_val)));
		case eOperandType::Double:
			return oc.createOperand(opType,std::to_string(std::get<4>(lhs_val) + std::get<4>(rhs_val)));
	}

	return nullptr;
}


IOperand const * Operand::operator-(const IOperand &rhs) const
{
	const auto [opType, lhs_val, rhs_val] = ops_for_arith(rhs);

	switch(opType) {
		case eOperandType::Int8:
			return oc.createOperand(opType,std::to_string(std::get<0>(lhs_val) - std::get<0>(rhs_val)));
		case eOperandType::Int16:
			return oc.createOperand(opType,std::to_string(std::get<1>(lhs_val) - std::get<1>(rhs_val)));
		case eOperandType::Int32:
			return oc.createOperand(opType,std::to_string(std::get<2>(lhs_val) - std::get<2>(rhs_val)));
		case eOperandType::Float:
			return oc.createOperand(opType,std::to_string(std::get<3>(lhs_val) - std::get<3>(rhs_val)));
		case eOperandType::Double:
			return oc.createOperand(opType,std::to_string(std::get<4>(lhs_val) - std::get<4>(rhs_val)));
	}

	return nullptr;
}


IOperand const * Operand::operator*(const IOperand &rhs) const
{
	const auto [opType, lhs_val, rhs_val] = ops_for_arith(rhs);

	switch(opType) {
		case eOperandType::Int8:
			return oc.createOperand(opType,std::to_string(std::get<0>(lhs_val) * std::get<0>(rhs_val)));
		case eOperandType::Int16:
			return oc.createOperand(opType,std::to_string(std::get<1>(lhs_val) * std::get<1>(rhs_val)));
		case eOperandType::Int32:
			return oc.createOperand(opType,std::to_string(std::get<2>(lhs_val) * std::get<2>(rhs_val)));
		case eOperandType::Float:
			return oc.createOperand(opType,std::to_string(std::get<3>(lhs_val) * std::get<3>(rhs_val)));
		case eOperandType::Double:
			return oc.createOperand(opType,std::to_string(std::get<4>(lhs_val) * std::get<4>(rhs_val)));
	}

	return nullptr;
}


IOperand const * Operand::operator/(const IOperand &rhs) const
{
	const auto [opType, lhs_val, rhs_val] = ops_for_arith(rhs);

	switch(opType) {
		case eOperandType::Int8:
			return oc.createOperand(opType,std::to_string(std::get<0>(lhs_val) / std::get<0>(rhs_val)));
		case eOperandType::Int16:
			return oc.createOperand(opType,std::to_string(std::get<1>(lhs_val) / std::get<1>(rhs_val)));
		case eOperandType::Int32:
			return oc.createOperand(opType,std::to_string(std::get<2>(lhs_val) / std::get<2>(rhs_val)));
		case eOperandType::Float:
			return oc.createOperand(opType,std::to_string(std::get<3>(lhs_val) / std::get<3>(rhs_val)));
		case eOperandType::Double:
			return oc.createOperand(opType,std::to_string(std::get<4>(lhs_val) / std::get<4>(rhs_val)));
	}

	return nullptr;
}


IOperand const * Operand::operator%(const IOperand &rhs) const
{
	const auto [opType, lhs_val, rhs_val] = ops_for_arith(rhs);

	switch(opType) {
		case eOperandType::Int8:
			return oc.createOperand(opType,std::to_string(std::get<0>(lhs_val) % std::get<0>(rhs_val)));
		case eOperandType::Int16:
			return oc.createOperand(opType,std::to_string(std::get<1>(lhs_val) % std::get<1>(rhs_val)));
		case eOperandType::Int32:
			return oc.createOperand(opType,std::to_string(std::get<2>(lhs_val) % std::get<2>(rhs_val)));
		case eOperandType::Float:
			return oc.createOperand(opType,std::to_string(std::fmod(std::get<3>(lhs_val), std::get<3>(rhs_val))));
		case eOperandType::Double:
			return oc.createOperand(opType,std::to_string(std::fmod( std::get<4>(lhs_val), std::get<4>(rhs_val))));
	}

	return nullptr;
}
