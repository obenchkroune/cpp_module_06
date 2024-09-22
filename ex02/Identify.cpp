#include "Identify.h"
#include <ctime>
#include <iostream>

Base::~Base()
{
}

Base *generate(void)
{
	switch (time(0) % 3) {
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "the identified pointer type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "the identified pointer type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "the identified pointer type is C" << std::endl;
}

void identify(Base &p)
{
	try {
		dynamic_cast<A&>(p);
		std::cout << "the identified reference type is A" << std::endl;
	} catch (std::exception &e){
		try {
			dynamic_cast<B&>(p);
			std::cout << "the identified reference type is B" << std::endl;
		} catch (std::exception &e){
			try {
				dynamic_cast<C&>(p);
				std::cout << "the identified reference type is C" << std::endl;
			} catch (std::exception &e){}
		}
	}
}

A::A()
{
}

B::B()
{
}

C::C()
{
}
