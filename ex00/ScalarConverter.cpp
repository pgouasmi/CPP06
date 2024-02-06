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

static bool isInputCorrect(char *s, double *nb, char *pEnd)
{
	*nb = strtod(s, &pEnd);

	/*checks if the only rest in pEnd is 'f', otherwise the input is wrong*/
	if (pEnd && pEnd[0] && strlen(pEnd) != 1)
	{
		std::cout << "Conversion of " << s << " is impossible" << std::endl;
		return false;
	}
	if (pEnd[0] && pEnd[0] != 'f')
	{
		if (strlen(s) == 1)
			*nb = static_cast<double>(pEnd[0]);
	}
	if (pEnd[0] &&pEnd[0] == 'f')
	{
		if (strlen(s) == 1)
			*nb = static_cast<double>(pEnd[0]);
	}
	return true;
}

static void displayInt(double nb)
{
	int iresult = static_cast<int>(nb);

//	std::cout << iresult << std::endl;

	std::cout << "int: ";
	if (nb > INT_MAX || nb < INT_MIN || nb != nb)
		std::cout << "impossible" << std::endl;
	else
		std::cout << iresult << std::endl;
}

static void displayDouble(double nb)
{
	std::cout << "double: ";
	if (nb > 999999 && nb == nb && !isinf(nb))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << nb;
	if ((nb - (long)nb) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

static void	displayChar(double nb)
{
	char cresult = static_cast<char>(nb);

	std::cout << "char: ";
	if (cresult != static_cast<char>(nb) || static_cast<char>(nb) != static_cast<int>(nb))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (!isprint(cresult))
	{
		if (nb < 0 || nb > 177 || nb != nb)
			std::cout << "impossible" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "\'" << cresult << "\'" << std::endl;
}

static void displayFloat(double nb)
{
	float fresult = static_cast<float>(nb);

	std::cout << "float: ";
	if (nb > 999999 && nb == nb && !isinf(nb))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << fresult;
	if (fresult - static_cast<long>(nb) == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void ScalarConverter::convert(char *s)
{
	char *pEnd = NULL;
	double nb;

	if (isInputCorrect(s, &nb, pEnd) == false)
		return ;


	displayChar(nb);
	displayInt(nb);
	displayFloat(nb);
	displayDouble(nb);

}
