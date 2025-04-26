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

		static int	detectType(const std::string& literal);
		static void	display(char c, int i, float f, double d);
		static void	handleChar(const std::string& literal);
		static void	handleInt(const std::string& literal);
		static void	handleFloat(const std::string& literal);
		static void	handleDouble(const std::string& literal);
		static void	handleEdge(const std::string& literal);

	public:
		static void	convert(const std::string& literal);
};

#endif
