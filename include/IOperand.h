//
// Created by Virgil Legros on 2/22/21.
//

#ifndef ABSTARCTVM_IOPERAND_H
#define ABSTARCTVM_IOPERAND_H

#include <string>
#include <array>
#include <functional>

enum class eOperandType {
    Int8,
    Int16,
    Int32,
    Float,
    Double
};

class IOperand {
public:
    virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
    virtual eOperandType getType( void ) const = 0; // Type of the instance
    virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
    virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
    virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
    virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
    virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
    virtual std::string const & toString( void ) const = 0; // String representation of the instance
    virtual ~IOperand( void ) {}
};

class OperandCreator {
private:
    IOperand const * createInt8( std::string const & value ) const;
    IOperand const * createInt16( std::string const & value ) const;
    IOperand const * createInt32( std::string const & value ) const;
    IOperand const * createFloat( std::string const & value ) const;
    IOperand const * createDouble( std::string const & value ) const;

    static const int OPERAND_TYPES_NUM = 5;
public:
    OperandCreator() = default;
    IOperand const * createOperand( eOperandType type, std::string const & value ) const;
};

template<typename T>
T specificTypeValue(const eOperandType type, std::string const & value) {
    switch (type) {
        case eOperandType::Int8:
        case eOperandType::Int16:
        case eOperandType::Int32: return std::stoi(value);
        case eOperandType::Float: return std::stof(value);
        case eOperandType::Double: return std::stod(value);
    }
    return 0;
}

template<typename T, eOperandType TYPE>
class Operand : public IOperand {
private:
    const std::string& Value;
    const eOperandType type = TYPE;
    OperandCreator oc;
public:
    Operand(const std::string& Value) : Value(Value) {
        ///possible adding overflow condtition for actual value
    }

    int getPrecision(void) const override { return static_cast<int>(type); } // Precision of the type of the instance
    eOperandType getType(void) const override { return type; } // Type of the instance
    IOperand const *operator+(IOperand const &rhs) const override {
        const eOperandType resultType = static_cast<int>(getType()) < static_cast<int>(rhs.getType()) ?
                rhs.getType() : getType();


        ///promote them
        ///do the arith
        ///return calculated type

    } // Sum
    IOperand const *operator-(IOperand const &rhs) const override {

    } // Difference
    IOperand const *operator*(IOperand const &rhs) const override {

    } // Product
    IOperand const *operator/(IOperand const &rhs) const override {

    } // Quotient
    IOperand const *operator%(IOperand const &rhs) const override {

    } // Modulo
    std::string const &toString(void) const override { return Value; }

};



#endif //ABSTARCTVM_IOPERAND_H
