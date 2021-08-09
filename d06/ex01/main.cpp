#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <ctime>

typedef struct s_data{

	int	i;
}	Data;

uintptr_t serialize(Data* ptr){

	std::cout << "Serialization" << std::endl;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw){

	std::cout << "Deserialization" << std::endl;
	return reinterpret_cast<Data *>(raw);
}

int main(void) {

	Data*		ptr1 = new Data;
	Data*		ptr2;
	uintptr_t	raw;

	std::srand(std::time(nullptr));
	ptr1->i = std::rand();

	std::cout << "ptr1 :" << std::endl
		<< "adress = " << ptr1 << std::endl
		<< "int    = " << ptr1->i << std::endl
	<< std::endl;

	raw = serialize(ptr1);
	ptr2 = deserialize(raw);

	std::cout  << std::endl << "ptr2 :" << std::endl
		<< "adress = " << ptr2 << std::endl
		<< "int    = " << ptr2->i
	<< std::endl;
	
	delete ptr1;

	return 0;
}
