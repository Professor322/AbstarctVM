//
// Created by professor on 2/23/21.
//

#include "OperandDerived.h"

Operand::Operand(const std::string &Value, const eOperandType type) : Value(Value), type(type), oc() {}

[[nodiscard]] std::tuple<eOperandType, Types, Types> Operand::ops_for_arith(IOperand const &rhs) const {
	eOperandType opType = getPrecision() < rhs.getPrecision() ? rhs.getType() : getType();
	return {opType, getVariant(opType, toString()), getVariant(opType, rhs.toString())};
}

bool Operand::operator==(const IOperand &rhs) const {
	auto Type = this->getType();

	if (Type != rhs.getType())
		return false;

	Types lhs_val = getVariant(Type, this->toString());
	Types rhs_val = getVariant(Type, rhs.toString());

	switch(Type) {
		case eOperandType::Int8:
			return std::get<int8_t>(lhs_val) == std::get<int8_t>(rhs_val);
		case eOperandType::Int16:
			return std::get<int16_t>(lhs_val) == std::get<int16_t>(rhs_val);
		case eOperandType::Int32:
			return std::get<int32_t>(lhs_val) == std::get<int32_t>(rhs_val);
		case eOperandType::Float:
			return std::fabs(std::get<float>(lhs_val) - std::get<float>(rhs_val)) < F_EPSILON;
		case eOperandType::Double:
			return std::fabs(std::get<double>(lhs_val) - std::get<double>(rhs_val)) < D_EPSILON;
	}
	return false;
}

IOperand const * Operand::operator+(const IOperand &rhs) const
{
	const auto [opType, lhs_val, rhs_val] = ops_for_arith(rhs);

	switch(opType) {
		case eOperandType::Int8:
			return oc.createOperand(opType,std::to_string(std::get<int8_t>(lhs_val) + std::get<int8_t>(rhs_val)));
		case eOperandType::Int16:
			return oc.createOperand(opType,std::to_string(std::get<int16_t>(lhs_val) + std::get<int16_t>(rhs_val)));
		case eOperandType::Int32:
			return oc.createOperand(opType,std::to_string(std::get<int32_t>(lhs_val) + std::get<int32_t>(rhs_val)));
		case eOperandType::Float: {
			std::stringstream ss;
			ss << std::fixed << std::setprecision(2) << std::get<float>(lhs_val) + std::get<float>(rhs_val);
			return oc.createOperand(opType, ss.str());
		}
		case eOperandType::Double: {
			std::stringstream ss;
			ss << std::fixed << std::setprecision(2) << std::get<double>(lhs_val) + std::get<double>(rhs_val);
			return oc.createOperand(opType, ss.str());
		}
	}

	return nullptr;
}


IOperand const * Operand::operator-(const IOperand &rhs) const
{
	const auto [opType, lhs_val, rhs_val] = ops_for_arith(rhs);

	switch(opType) {
		case eOperandType::Int8:
			return oc.createOperand(opType,std::to_string(std::get<int8_t>(lhs_val) - std::get<int8_t>(rhs_val)));
		case eOperandType::Int16:
			return oc.createOperand(opType,std::to_string(std::get<int16_t>(lhs_val) - std::get<int16_t>(rhs_val)));
		case eOperandType::Int32:
			return oc.createOperand(opType,std::to_string(std::get<int32_t>(lhs_val) - std::get<int32_t>(rhs_val)));
		case eOperandType::Float: {
			std::stringstream ss;
			ss << std::fixed << std::setprecision(2) << std::get<float>(lhs_val) - std::get<float>(rhs_val);
			return oc.createOperand(opType, ss.str());
		}
		case eOperandType::Double: {
			std::stringstream ss;
			ss << std::fixed << std::setprecision(2) << std::get<double>(lhs_val) - std::get<double>(rhs_val);
			return oc.createOperand(opType, ss.str());
		}
	}

	return nullptr;
}


IOperand const * Operand::operator*(const IOperand &rhs) const
{
	const auto [opType, lhs_val, rhs_val] = ops_for_arith(rhs);

	switch(opType) {
		case eOperandType::Int8:
			return oc.createOperand(opType,std::to_string(std::get<int8_t>(lhs_val) * std::get<int8_t>(rhs_val)));
		case eOperandType::Int16:
			return oc.createOperand(opType,std::to_string(std::get<int16_t>(lhs_val) * std::get<int16_t>(rhs_val)));
		case eOperandType::Int32:
			return oc.createOperand(opType,std::to_string(std::get<int32_t>(lhs_val) * std::get<int32_t>(rhs_val)));
		case eOperandType::Float: {
			std::stringstream ss;
			ss << std::setprecision(2) << std::fixed << std::get<float>(lhs_val) * std::get<float>(rhs_val);;
			return oc.createOperand(opType, ss.str());
		}
		case eOperandType::Double: {
			std::stringstream ss;
			ss << std::fixed << std::setprecision(2) << std::get<double>(lhs_val) * std::get<double>(rhs_val);
			return oc.createOperand(opType, ss.str());
		}
	}

	return nullptr;
}


IOperand const * Operand::operator/(const IOperand &rhs) const
{
	const auto [opType, lhs_val, rhs_val] = ops_for_arith(rhs);

	switch(opType) {
		case eOperandType::Int8:
			return oc.createOperand(opType,std::to_string(std::get<int8_t>(lhs_val) / std::get<int8_t>(rhs_val)));
		case eOperandType::Int16:
			return oc.createOperand(opType,std::to_string(std::get<int16_t>(lhs_val) / std::get<int16_t>(rhs_val)));
		case eOperandType::Int32:
			return oc.createOperand(opType,std::to_string(std::get<int32_t>(lhs_val) / std::get<int32_t>(rhs_val)));
		case eOperandType::Float: {
			std::stringstream ss;
			ss << std::setprecision(2) << std::get<float>(lhs_val) / std::get<float>(rhs_val);
			return oc.createOperand(opType, ss.str());
		}
		case eOperandType::Double: {
			std::stringstream ss;
			ss << std::fixed << std::setprecision(2) << std::get<double>(lhs_val) / std::get<double>(rhs_val);
			return oc.createOperand(opType, ss.str());
		}
	}

	return nullptr;
}


IOperand const * Operand::operator%(const IOperand &rhs) const
{
	const auto [opType, lhs_val, rhs_val] = ops_for_arith(rhs);

	switch(opType) {
		case eOperandType::Int8:
			return oc.createOperand(opType,std::to_string(std::get<int8_t>(lhs_val) % std::get<int8_t>(rhs_val)));
		case eOperandType::Int16:
			return oc.createOperand(opType,std::to_string(std::get<int16_t>(lhs_val) % std::get<int16_t>(rhs_val)));
		case eOperandType::Int32:
			return oc.createOperand(opType,std::to_string(std::get<int32_t>(lhs_val) % std::get<int32_t>(rhs_val)));
		case eOperandType::Float: {
			std::stringstream ss;
			ss << std::fixed << std::setprecision(2) << std::fmod(std::get<float>(lhs_val), std::get<float>(rhs_val));
			return oc.createOperand(opType, ss.str());
		}
		case eOperandType::Double: {
			std::stringstream ss;
			ss << std::fixed << std::setprecision(2) << std::fmod(std::get<double>(lhs_val), std::get<double>(rhs_val));
			return oc.createOperand(opType, ss.str());
		}
	}

	return nullptr;
}
