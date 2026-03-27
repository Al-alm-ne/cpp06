#include "Base.hpp"
#include "ABC.hpp"

#include <ctime>
#include <cstdlib>
#include <exception>
#include <iostream>

Base::~Base() {}

Base*	generate(void)
{
	int r = rand() % 3;

	switch (r)
	{
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
	}
	return NULL;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))//operador de conversão de tipos em C++ usado especificamente para hierarquias de classes polimórficas.
		std::cout << BCYN << "Objected pointed: A" << NC << "\n";
	else if (dynamic_cast<B*>(p))
		std::cout << BCYN << "Objected pointed: B" << NC << "\n";
	else if (dynamic_cast<C*>(p))
		std::cout << BCYN << "Objected pointed: C" << NC << "\n";
	else
	 	std::cout << BRED << "Dynamic_cast failed!" << NC << "\n";
}

void	identify(Base& p)
{
	try {
		(void) dynamic_cast<A&>(p);
		std::cout << BYEL << "Reference returned: A" << NC << "\n";
		return;
	}
	catch (std::exception& e) {}

	try {
		(void) dynamic_cast<B&>(p);
		std::cout << BYEL << "Reference returned: B" << NC << "\n";
		return;
	}
	catch (std::exception& e) {}

	try {
		(void) dynamic_cast<C&>(p);
		std::cout << BYEL << "Reference returned: C" << NC << "\n";
		return;
	}
	catch (std::exception& e) {}
}