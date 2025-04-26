#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# define UNKNOWN 0
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4
# define EDGE 5


#include <iostream>
#include <sstream>
#include <iomanip>
#include <cctype>

class	ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copied);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& base);

	public:
		static void	convert(const std::string& literal);
};

#endif
