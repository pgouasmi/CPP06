/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:16:19 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/02/05 17:16:19 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <math.h>
#include <climits>

#define CHAR  1
#define INT  2
#define DOUBLE 3
#define FLOAT 4


class ScalarConverter {

private:
	ScalarConverter();


public:
	~ScalarConverter();
	ScalarConverter(ScalarConverter &obj);
	ScalarConverter &operator=(const ScalarConverter &obj);

	static void	convert(char *s);

};


#endif
