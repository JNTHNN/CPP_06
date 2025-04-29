#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

struct Data
{
	std::string	name;
	int					value;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& copied);
		~Serializer();
		Serializer& operator= (const Serializer& base);

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
