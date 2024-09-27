#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cerrno>
#include <limits>

using std::numeric_limits;
using std::cout;

ScalarType ScalarConverter::_type = TYPE_UNKNOWN;
int ScalarConverter::_int = 0;
char ScalarConverter::_char = 0;
float ScalarConverter::_float = 0;
double ScalarConverter::_double = 0;

void ScalarConverter::convert(const string &input)
{
	_type = ScalarConverter::identify(input);
	getDouble();
	printChar();
	printInt();
	printFloat();
	printDouble();
}

ScalarType ScalarConverter::identify(const std::string &input)
{
	const char	*str = input.c_str();
    char		*end_ptr;
	int			sign = 1;
    
    while (*str && std::isspace(*str)) {
        str++;
    }

	if (strlen(str) == 1 && !std::isdigit(*str)) {
		_char = *str;
        return TYPE_CHAR;
    }

	if (*str == '+' || *str == '-') {
		if (*str == '-')
			sign = -1;
		str++;
	}

    long int_result = std::strtol(str, &end_ptr, 10);
    if (!*end_ptr && int_result >= numeric_limits<int>::min() && int_result <= numeric_limits<int>::max()) {
		_int = sign * int_result;
        return TYPE_INT;
    }

    errno = 0;
    float float_result = std::strtof(str, &end_ptr);
    if (*end_ptr == 'f' && *(end_ptr + 1) == '\0' && errno != ERANGE) {
		_float = float_result * sign;
        return TYPE_FLOAT;
    }

    errno = 0;
    double double_result = std::strtod(str, &end_ptr);
    if (*end_ptr == '\0' && errno != ERANGE) {
		_double = double_result * sign;
        return TYPE_DOUBLE;
    }

    return TYPE_UNKNOWN;
}

void ScalarConverter::printChar()
{
	cout << "char: ";
	if (_double < numeric_limits<char>::min() || _double > numeric_limits<char>::max() || _type == TYPE_UNKNOWN)
		cout << "impossible";
	else {
		_char = static_cast<char>(_double);
		if (std::isprint(_char))
			cout << _char;
		else
			cout << "Non displayable";
	}
	cout << '\n';
}

void ScalarConverter::printInt()
{
	cout << "int: ";
	if (_double < numeric_limits<int>::min() || _double > numeric_limits<int>::max() || _type == TYPE_UNKNOWN)
		cout << "impossible";
	else {
		_int = static_cast<int>(_double);
		cout << _int;
	}
	cout << '\n';
}

void ScalarConverter::printFloat()
{
	cout << "float: ";
	if (_double < -numeric_limits<float>::max() || _double > numeric_limits<float>::max() || _type == TYPE_UNKNOWN)
		cout << "impossible";
	else {
		_float = static_cast<float>(_double);
		cout << _float;
		if (::fmodf(_float, 1.0f) == 0)
			cout << ".0";
		cout << "f";
	}
	cout << '\n';
}

void ScalarConverter::printDouble()
{
	cout << "double: ";
	if (_type == TYPE_UNKNOWN)
		cout << "impossible";
	else {
		cout << _double;
		if (::fmod(_float, 1.0) == 0)
			cout << ".0";
	}
	cout << "\n";
}

void ScalarConverter::getDouble()
{
	switch (_type) {
		case TYPE_FLOAT:
			_double = static_cast<double>(_float);
			break;
		case TYPE_INT:
			_double = static_cast<double>(_int);
			break;
		case TYPE_CHAR:
			_char = static_cast<double>(_char);
			break;
		default:
			break;
	} 
}

