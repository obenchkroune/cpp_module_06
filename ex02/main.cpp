#include "Identify.h"

int main() {
	{
		Base *random = generate();

		identify(random);

		delete random;
	}

	{
		Base *random = generate();

		Base &base = *random;

		identify(base);

		delete random;
	}
	return 0;
}
