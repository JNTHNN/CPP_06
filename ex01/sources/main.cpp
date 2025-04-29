#include "../includes/Serializer.hpp"
#include <iostream>

int main(void)
{
    Data data;
    data.value = 19;
    data.name = "jgasparo";

    std::cout << "Original Data:" << std::endl;
    std::cout << "Value: " << data.value << ", Name: " << data.name << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized uintptr_t: " << raw << std::endl;

    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "Value: " << deserialized->value << ", Name: " << deserialized->name << std::endl;
	std::cout << "Deserialized address: " << deserialized << std::endl;
	std::cout << "Data address: " << &data << std::endl;

    if (&data == deserialized)
        std::cout << "\033[32mSuccess: The deserialized pointer matches the original pointer.\033[0m" << std::endl;
    else
        std::cout << "\033[31mError: The deserialized pointer does not match the original pointer.\033[0m" << std::endl;

    return 0;
}
