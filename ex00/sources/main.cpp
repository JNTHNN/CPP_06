#include "../includes/ScalarConverter.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
		return std::cout << "Error: invalid numbers of arguments" << std::endl, 1;
	ScalarConverter::convert(argv[1]);
	return 0;
}
