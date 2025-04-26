#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
    return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copied)
{
    (void)copied;
    return ;
}

ScalarConverter::~ScalarConverter(void)
{
    return ;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& base)
{
    (void)base;
    return *this;
}

int stringToInt(const std::string& str)
{
    std::stringstream ss(str);
    int result;
    ss >> result;
    if (ss.fail() || !ss.eof())
        throw std::invalid_argument("Invalid integer format");
    return result;
}

float stringToFloat(const std::string& str)
{
    std::string temp = str;

    if (temp.size() > 0 && temp[temp.size() - 1] == 'f')
        temp.erase(temp.size() - 1);
    std::stringstream ss(temp);
    float result;
    ss >> result;

    if (ss.fail() || !ss.eof())
        throw std::invalid_argument("Invalid float format");

    return result;
}

double stringToDouble(const std::string& str)
{
    std::stringstream ss(str);
    double result;
    ss >> result;
    if (ss.fail() || !ss.eof())
        throw std::invalid_argument("Invalid double format");
    return result;
}

/* Handlers */
void ScalarConverter::handleChar(const std::string& literal)
{
    char c = literal[0];
    display(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
}

void ScalarConverter::handleInt(const std::string& literal)
{
    try
    {
        int i = stringToInt(literal);
        display(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void ScalarConverter::handleFloat(const std::string& literal)
{
    try
    {
        float f = stringToFloat(literal);
        display(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void ScalarConverter::handleDouble(const std::string& literal)
{
    try
    {
        double d = stringToDouble(literal);
        display(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
    }
    catch (const std::exception& e)
    {
        std::cerr << "The type conversion is impossible." << std::endl;
    }
}

void ScalarConverter::display(char c, int i, float f, double d)
{
    std::cout << "char: ";
    if (std::isprint(c))
        std::cout << c;
    else
        std::cout << "Non displayable";
    std::cout << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::handleEdge(const std::string& literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal;
	if (literal.find('f') == std::string::npos)
		std::cout << "f" << std::endl;
	else
		std::cout << std::endl;
	std::cout << "double: " << literal << std::endl;
}

int ScalarConverter::detectType(const std::string& literal)
{
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(static_cast<unsigned char>(literal[0])))
        return CHAR;
    if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos && literal != "nan")
        return INT;
    if (literal[literal.size() - 1] == 'f' && literal.find('.') != std::string::npos)
        return FLOAT;
    if (literal.find('.') != std::string::npos)
        return DOUBLE;
	if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "nanf" || literal == "+inff" || literal == "-inff")
		return EDGE;
    return UNKNOWN;
}

void ScalarConverter::convert(const std::string& literal)
{
    switch (detectType(literal))
    {
        case CHAR:
            handleChar(literal);
            break;
        case INT:
            handleInt(literal);
            break;
        case FLOAT:
            handleFloat(literal);
            break;
        case DOUBLE:
            handleDouble(literal);
            break;
		case EDGE:
			handleEdge(literal);
			break;
        default:
            std::cout << "Error: Invalid literal type" << std::endl;
            break;
    }
}
