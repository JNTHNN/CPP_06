#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::~Base(void)
{
	return;
}

Base*	generate(void)
{
	std::srand(std::time(0));
	int	random = std::rand() % 3;

	switch (random)
	{
		case 0:
			std::cout << "Generate A" << std::endl;
			return new A();
			break;
			case 1:
			std::cout << "Generate B" << std::endl;
			return new B();
			break;
			case 2:
			std::cout << "Generate C" << std::endl;
			return new C();
			break;
		default:
			std::cout << "Error generate" << std::endl;
			return 0;
			break;
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void	identify(Base& p)
{
    try
	{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
	catch (const std::exception& e)
	{
		// std::cout << "Error: A cast fail : " << e.what() << std::endl;
	}
	
    try
	{
		(void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
	catch (const std::exception& e)
	{
		// std::cout << "Error: B cast fail : " << e.what() << std::endl;
	}
	
    try
	{
		(void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
	catch (const std::exception& e)
	{
		// std::cout << "Error: C cast fail : " << e.what() << std::endl;
	}

    std::cout << "Unknown type" << std::endl;
}