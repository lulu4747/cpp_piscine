#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <ctime>

class Base{

public:

	virtual ~Base(void);

};

class A : public Base{};
class B : public Base{};
class C : public Base{};

Base::~Base(void){};

Base * generate(void){

	int		r;

	std::srand(std::time(nullptr));
	r = std::rand() % 3;
	if (r == 0)
		return new A();
	else if (r == 1)
		return new B();
	return new C();
}

void identify(Base* p){

	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
	return ;
}

void identify(Base& p){

	try
	{
		static_cast<void>(dynamic_cast<A &>(p));
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::bad_cast &e){};
	try
	{
		static_cast<void>(dynamic_cast<B &>(p));
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::bad_cast &e){};
	std::cout << "C" << std::endl;

	return ;
}

int main(void) {

	Base*	p = generate();

	identify(p);
	identify(*p);
	return 0;
}
