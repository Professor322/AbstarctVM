//
// Created by Virgil Legros on 2/22/21.
//

#include "IOperand.h"

const IOperand * OperandCreator::createInt8(const std::string &value) const {
    return new Operand<int8_t, eOperandType::Int8>(value);
}

const IOperand * OperandCreator::createInt16(const std::string &value) const {
    return new Operand<int16_t, eOperandType::Int16>(value);
}

const IOperand * OperandCreator::createInt32(const std::string &value) const {
    return new Operand<int32_t, eOperandType::Int32>(value);
}

const IOperand * OperandCreator::createFloat(const std::string &value) const {
    return new Operand<float, eOperandType::Float>(value);
}

const IOperand * OperandCreator::createDouble(const std::string &value) const {
    return new Operand<double, eOperandType::Double>(value);
}

IOperand const * OperandCreator::createOperand(eOperandType type, const std::string &value) const {
    static std::array<std::function<IOperand const *(const OperandCreator&, std::string const&)>, OPERAND_TYPES_NUM> mainCreator = {
            &OperandCreator::createInt8,
            &OperandCreator::createInt16,
            &OperandCreator::createInt32,
            &OperandCreator::createFloat,
            &OperandCreator::createDouble
    };

    return mainCreator[static_cast<int>(type)](OperandCreator(), value);
}


