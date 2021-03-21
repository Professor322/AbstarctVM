//
// Created by professor on 3/21/21.
//

#ifndef ABSTARCTVM_ERRORHANDLER_H
#define ABSTARCTVM_ERRORHANDLER_H

#include <exception>
#include <string>
#include <iostream>
#include <sstream>

class ErrorHandler : public std::exception {
	std::string ErrorsDescription;
	size_t ErrorCounter;
public:
	void addError(const std::string& Description) {
		ErrorsDescription += Description + "\n";
		ErrorCounter++;
	}
	[[nodiscard]] const char* what() const noexcept override {
		//std::stringstream  ss;
		//ss << ErrorsDescription << '\n' << ErrorCounter << '\n';
		return ErrorsDescription.c_str();
	}
	[[nodiscard]] size_t getErrorCounter() const {
		return ErrorCounter;
	}
};


#endif //ABSTARCTVM_ERRORHANDLER_H
