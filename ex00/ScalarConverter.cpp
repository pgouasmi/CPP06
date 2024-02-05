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

void ScalarConverter::convert(char *s)
{
	char *pEnd = NULL;

	double nb;

	if (isalpha(s[0]))
	{
		if (strlen(s) != 1)
		{
			std::cout << "Conversion of " << s << " is impossible" << std::endl;
			return ;
		}
		else
			nb = s[0];
	}
	else
	{
		nb = strtod(s, &pEnd);
		std::cout << pEnd << std::endl;
		std::cout << nb << std::endl;

		/*checks if the only rest in pEnd is 'f', otherwise the input is wrong*/
		if (pEnd && pEnd[0]) {
			size_t i = 0;
			while (pEnd[i])
				i++;
			if (i != 1 || pEnd[0] != 'f') {
				std::cout << "Conversion of " << s << " is impossible" << std::endl;
				return;
			}
		}
	}

	char cresult = static_cast<char>(nb);
	std::cout << "char : " << cresult << std::endl;
	int iresult = static_cast<int>(nb);
	std::cout << "int : " << iresult << std::endl;
	std::cout << "double : " << nb << std::endl;
	std::cout << "float : " << static_cast<float>(nb);
}
