#pragma once

#include <exception>

#include <string>

template<class T>
class InvalidEnumValueException : public std::exception {
public:
	InvalidEnumValueException(T val) : val(val) {}

	virtual const char* what() const throw()
	{
		return "Invalid value in enum";
	}
private:
	T val;
};

class InvalidStringValueException : public std::exception {
public:
	InvalidStringValueException(std::string val) : val(val) {
		str = std::string("Invalid string value '") + val + "'";
		ret = str.c_str();
	}

	virtual const char* what() const throw()
	{
		return ret;
	}
private:
	std::string val;
	std::string str;
	const char* ret;
};

template<class T>
class NullValueUsed : public std::exception {
public:
	virtual const char* what() const throw()
	{
		return "Null value used";
	}
};

