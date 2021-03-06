//
// Created by Virgil Legros on 2/22/21.
//

#ifndef ABSTARCTVM_IOPERAND_H
#define ABSTARCTVM_IOPERAND_H

#include <string>
#include <array>
#include <functional>
#include <utility>
#include <variant>
#include <tuple>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>

enum class eOperandType {
    Int8,
    Int16,
    Int32,
    Float,
    Double
};

class IOperand {
public:
    virtual int getPrecision() const = 0; // Precision of the type of the instance
    virtual eOperandType getType() const = 0; // Type of the instance
    virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
    virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
    virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
    virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
    virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
	virtual bool operator==(const IOperand &rhs) const = 0;
    [[nodiscard]] virtual std::string const & toString() const = 0; // String representation of the instance
    virtual ~IOperand() {}
};

class OperandCreator {
private:
    [[nodiscard]] IOperand const * createInt8( std::string const & value ) const;
    [[nodiscard]] IOperand const * createInt16( std::string const & value ) const;
    [[nodiscard]] IOperand const * createInt32( std::string const & value ) const;
    [[nodiscard]] IOperand const * createFloat( std::string const & value ) const;
    [[nodiscard]] IOperand const * createDouble( std::string const & value ) const ;

    static const int OPERAND_TYPES_NUM = 5;
public:
    OperandCreator() = default;
    [[nodiscard]] IOperand const * createOperand( eOperandType type, std::string const & value ) const;
  //  ~OperandCreator() { std::cout << "Destroying the OC\n"; }
};





#endif //ABSTARCTVM_IOPERAND_H
