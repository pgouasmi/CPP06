/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:15:48 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/02/05 17:15:48 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter &obj)
{
	(void) obj;
}

ScalarConverter::~ScalarConverter() {}

static bool ischar(std::string str, char *pEnd)
{
	return (str.length() == 1 && strlen(pEnd) == 1 ? true : false);
}

static bool isint(std::string str, double nb, long lnb, char *pEnd)
{
	(void)nb;
	if (!pEnd[0] && str.find_first_of('.') == std::string::npos && (lnb <= INT_MAX && lnb >= INT_MIN))
		return true;
	return false;
}

static bool isdouble(double nb, long lnb, char *pEnd, std::string str)
{
	if ((isnan(nb) || isinf(nb) || lnb > INT_MAX || lnb < INT_MIN || (str.find_first_of('.') != std::string::npos)) && !pEnd[0])
		return true;
	return false;
}

static bool isfloat(std::string str, char *pEnd)
{
	return ((str.find_first_of('.') != std::string::npos || str == "inff" || str == "-inff" || str == "+inff" || str == "nanf" || str == "-nanf") && pEnd[0] == 'f' ? true : false);
}

static bool	detectType(char *s, double *nb, int *type)
{
	char *pEnd;
	std::string str(s);
	*nb = strtod(s, &pEnd);
	long lnb = static_cast<long>(*nb);

	if (strlen(pEnd) > 1)
		return false;
	if (ischar(str, pEnd))
	{
		*type = CHAR;
		return true;
	}
	if (isint(str, *nb, lnb, pEnd))
	{
		*type = INT;
		return true;
	}
	if (isdouble(*nb, lnb, pEnd, str))
	{
		*type = DOUBLE;
		return true;
	}
	if (isfloat(str, pEnd))
	{
		*type = FLOAT;
		return true;
	}
	return false;
}

template<typename T>
void printchar(T value)
{
	std::cout << "char: ";

	char toPrint = static_cast<char>(value);
	if (value < 0 || value > 127 || isnan(value))
		std::cout << "impossible" << std::endl;
	else if (!isprint(toPrint))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << toPrint << std::endl;
}

template<typename T>
void printint(T value)
{
	std::cout << "int: ";

	int toPrint = static_cast<int>(value);
	if (value < INT_MIN || value > INT_MAX)
		std::cout << "overflow" << std::endl;
	else if (isnan(value) || isinf(value))
		std::cout << "impossible" << std::endl;
	else
		std::cout << toPrint << std::endl;
}

template<typename T>
void printdouble(T value)
{
	std::cout << "double: ";

	double toPrint = static_cast<double>(value);
	std::cout << toPrint;
	long long nb = static_cast<long long>(value);
	if (nb == value)
		std::cout << ".0";
	std::cout << std::endl;
}

template<typename T>
void printfloat(T value)
{
	std::cout << "float: ";

	float toPrint = static_cast<float>(value);
	std::cout << toPrint;
	long long nb = static_cast<long long>(value);
	if (nb == value)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void displayChar(char *s)
{
	char c = static_cast<char>(s[0]);

	printchar(c);
	printint(c);
	printdouble(c);
	printfloat(c);
}

void displayInt(char *s)
{
	int n = atoi(s);

	printchar(n);
	printint(n);
	printdouble(n);
	printfloat(n);
}

void displayDouble(char *s)
{
	char *pEnd;
	double n = strtod(s, &pEnd);

	printchar(n);
	printint(n);
	printdouble(n);
	printfloat(n);
}

void displayFloat(char *s)
{
	char *pEnd;
	double n = strtof(s, &pEnd);

	printchar(n);
	printint(n);
	printdouble(n);
	printfloat(n);
}

void ScalarConverter::convert(char *s)
{
	double nb;
	int type;

	if (detectType(s, &nb, &type) == false)
	{
		std::cout << "Conversion of \'" << s << "\' is impossible" << std::endl;
		return;
	}

//	std::cout << type << std::endl;

	if (type == CHAR)
		displayChar(s);
	if (type == INT)
		displayInt(s);
	if (type == DOUBLE)
		displayDouble(s);
	if (type == FLOAT)
		displayFloat(s);

}
