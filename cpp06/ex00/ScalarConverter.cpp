#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>
#include <cctype>


ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& literal) {
	return (literal.length() == 1);
}

bool ScalarConverter::isInt(const std::string& literal) {
	if (literal.empty()) return false;
	
	std::istringstream iss(literal);
	int value;
	iss >> std::noskipws >> value;
	
	return iss.eof() && !iss.fail();
}

bool ScalarConverter::isFloat(const std::string& literal) {
	if (literal.empty()) return false;
	if (literal == "nanf" || literal == "+inff" || literal == "-inff") return true;
	
	if (literal[literal.length() - 1] != 'f') return false;
	
	std::string truncated = literal.substr(0, literal.length() - 1);
	std::istringstream iss(truncated);
	float value;
	iss >> std::noskipws >> value;
	
	return iss.eof() && !iss.fail();
}

bool ScalarConverter::isDouble(const std::string& literal) {
	if (literal.empty()) return false;
	if (literal == "nan" || literal == "+inf" || literal == "-inf") return true;
	
	std::istringstream iss(literal);
	double value;
	iss >> std::noskipws >> value;
	
	return iss.eof() && !iss.fail();
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
	return (literal == "nan" || literal == "+inf" || literal == "-inf" ||
			literal == "nanf" || literal == "+inff" || literal == "-inff");
}

void ScalarConverter::printChar(char c) {
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(int i) {
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
	std::cout << "float: " << f;
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
	std::cout << "double: " << d;
	if (d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convertFromChar(char c) {
	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void ScalarConverter::convertFromInt(int i) {
	if (i >= 0 && i <= 127) {
		printChar(static_cast<char>(i));
	} else {
		std::cout << "char: impossible" << std::endl;
	}
	
	printInt(i);
	printFloat(static_cast<float>(i));
	printDouble(static_cast<double>(i));
}

void ScalarConverter::convertFromFloat(float f) {
	if (std::isnan(f) || std::isinf(f)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	} else {
		if (f >= 0 && f <= 127) {
			printChar(static_cast<char>(f));
		} else {
			std::cout << "char: impossible" << std::endl;
		}
		
		if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max()) {
			printInt(static_cast<int>(f));
		} else {
			std::cout << "int: impossible" << std::endl;
		}
	}
	
	printFloat(f);
	printDouble(static_cast<double>(f));
}

void ScalarConverter::convertFromDouble(double d) {
	if (std::isnan(d) || std::isinf(d)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	} else {
		if (d >= 0 && d <= 127) {
			printChar(static_cast<char>(d));
		} else {
			std::cout << "char: impossible" << std::endl;
		}
		
		if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max()) {
			printInt(static_cast<int>(d));
		} else {
			std::cout << "int: impossible" << std::endl;
		}
	}
	
	if (d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max()) {
		printFloat(static_cast<float>(d));
	} else {
		std::cout << "float: impossible" << std::endl;
	}
	
	printDouble(d);
}

void ScalarConverter::convertFromPseudoLiteral(const std::string& literal) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	
	if (literal == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else if (literal == "+inff") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	} else if (literal == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	} else if (literal == "nan") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else if (literal == "+inf") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	} else if (literal == "-inf") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string& literal) {
	if (literal.empty()) {
		std::cout << "Error: Empty literal" << std::endl;
		return;
	}
	if (isPseudoLiteral(literal)) {
		convertFromPseudoLiteral(literal);
	} else if (isInt(literal)) {
		std::istringstream iss(literal);
		int value;
		iss >> value;
		convertFromInt(value);
	} else if (isChar(literal)) {
		convertFromChar(literal[0]);
	} else if (isFloat(literal)) {
		float value;
		if (literal == "nanf") {
			value = std::numeric_limits<float>::quiet_NaN();
		} else if (literal == "+inff") {
			value = std::numeric_limits<float>::infinity();
		} else if (literal == "-inff") {
			value = -std::numeric_limits<float>::infinity();
		} else {
			std::string truncated = literal.substr(0, literal.length() - 1);
			std::istringstream iss(truncated);
			iss >> value;
		}
		convertFromFloat(value);
	} else if (isDouble(literal)) {
		double value;
		if (literal == "nan") {
			value = std::numeric_limits<double>::quiet_NaN();
		} else if (literal == "+inf") {
			value = std::numeric_limits<double>::infinity();
		} else if (literal == "-inf") {
			value = -std::numeric_limits<double>::infinity();
		} else {
			std::istringstream iss(literal);
			iss >> value;
		}
		convertFromDouble(value);
	} else {
		try {
			std::istringstream iss(literal);
			double value;
			iss >> value;
			
			if (!iss.fail()) {
				convertFromDouble(value);
			} else {
				std::cout << "Error: Unrecognized literal type" << std::endl;
			}
		} catch (...) {
			std::cout << "Error: Unrecognized literal type" << std::endl;
		}
	}
}