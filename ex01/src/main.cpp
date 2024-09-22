#include "Serializer.h"
#include <iostream>

int main(int ac, char **av) {
	if (ac != 2)
		return 1;
	Data data;

	data.value = av[1];
	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "Serialized Data: " << serialized << std::endl;
	Data* raw = Serializer::deserialize(serialized);
	if (raw == &data)
		std::cout << "Raw Data: " << raw->value << std::endl;
	return 0;
}
