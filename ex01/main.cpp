
#include "Serializer.hpp"

int main()
{
	Data *test = new Data(8);

	uintptr_t p = Serializer::serialize(test);
	std::cout << (Serializer::deserialize(p))->content << std::endl;
	std::cout << "original: " << test << "\nSerialized " << Serializer::deserialize(p) << std::endl;

	delete test;
	return 0;
}