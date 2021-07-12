#include <iostream>
#include <string>
#include <fstream>

static std::string	replace(std::ifstream& is, std::string& s1, std::string& s2){

	std::string		buffer = "";

	while (!is.eof())
		buffer += static_cast <char>(is.get());
	for (size_t i  = buffer.find(s1); i != std::string::npos; i = buffer.find(s1))
	{
		buffer.erase(i, s1.size());
		buffer.insert(i, s2);
	}
	return buffer;
}

int	main(int ac, char **av){

	if (ac != 4)
	{
		std::cerr << "Error:arguments" << std::endl;
		return 1;
	}

	std::ifstream	is(av[1]);
	std::string		str[3] = {av[1], av[2], av[3]};

	if (is.fail())
	{
		std::cerr << "Error:open" << std::endl;
		return 1;
	}

	if (str[2].find(str[1]) != std::string::npos)
	{
		is.close();
		std::cerr << "Error:arguments" << std::endl;
		return 1;
	}

	std::ofstream	os(str[0] + ".replace");

	os << replace(is, str[1], str[2]) << std::endl;
	os.close();
	is.close();
	return 0;
}