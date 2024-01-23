#pragma once
#include <iostream>
#include <exception>
#include <map>

class Exception : public std::exception
{
	typedef std::map<int, std::string> Error_container;
	inline static Error_container m_code_error;

	int m_code;
public:
	Exception(int _code) : m_code(_code) {}

	static void Create_error(int _code, std::string _out_put_error)
	{
		m_code_error[_code] = _out_put_error;
	}

	virtual const char* what() const
	{
		if (m_code_error.find(this->m_code) != m_code_error.end())
			return m_code_error[this->m_code].c_str();

		return "Code error doesn't exist";
	}
};