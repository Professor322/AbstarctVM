//
// Created by Virgil Legros on 2/22/21.
//

#include "IOperand.h"
#include "OperandDerived.h"

const IOperand * OperandCreator::createInt8(const std::string &value) const {
    return new Operand(value, eOperandType::Int8);
}

const IOperand * OperandCreator::createInt16(const std::string &value) const {
    return new Operand(value, eOperandType::Int16);
}

const IOperand * OperandCreator::createInt32(const std::string &value) const {
    return new Operand(value, eOperandType::Int32);
}

const IOperand * OperandCreator::createFloat(const std::string &value) const {
    return new Operand(value, eOperandType::Float);
}

const IOperand * OperandCreator::createDouble(const std::string &value) const {
    return new Operand(value, eOperandType::Double);
}


//todo overlook this because for every funciton call we create a new OperandCreator, this is not right
IOperand const * OperandCreator::createOperand(eOperandType type, std::string const &value) const {
    static std::array<std::function<IOperand const *(std::string const&)>, OPERAND_TYPES_NUM> mainCreator = {
            std::bind(&OperandCreator::createInt8, this, std::placeholders::_1),
			std::bind(&OperandCreator::createInt16, this, std::placeholders::_1),
			std::bind(&OperandCreator::createInt32, this, std::placeholders::_1),
			std::bind(&OperandCreator::createFloat, this, std::placeholders::_1),
			std::bind(&OperandCreator::createDouble, this, std::placeholders::_1),
    };

    return mainCreator[static_cast<size_t>(type)](value);
}

