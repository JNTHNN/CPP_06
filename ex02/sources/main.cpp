#include "../includes/Base.hpp"

int main()
{
    Base* obj = generate();

    std::cout << "Identifying via pointer: ";
    identify(obj);

    std::cout << "Identifying via reference: ";
    identify(*obj);

    delete obj;

    return 0;
}