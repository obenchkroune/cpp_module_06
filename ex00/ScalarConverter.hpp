#pragma once

#include <string>

using std::string;

enum ScalarType {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_UNKNOWN
};

class ScalarConverter {
public:
	static void convert(const string &input);
	
private:
	static ScalarType _type;
	static int _int;
	static char _char;
	static float _float;
	static double _double;

	static ScalarType identify(const string &input);
	static void getDouble();
	static void printChar();
	static void printInt();
	static void printFloat();
	static void printDouble();
	ScalarConverter();
	~ScalarConverter();
};
