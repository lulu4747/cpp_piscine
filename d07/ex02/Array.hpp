#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <string>
# include <sstream>

template < typename T >
class Array
{

public:

	Array(void):_data(NULL),_size(0){}
	Array(unsigned int n):_data(new T[n]),_size(n){}

	~Array(void){

		if (this->_size)
			delete[] _data;
		return ;
	}

	Array(Array const & src):_data(NULL),_size(0){

		*this = src;
	}

	Array &	operator=(Array const &rhs){

		if (this != &rhs)
		{
			if (this->_size != rhs.size())
			{
				delete[] _data;
				this->_size = rhs.size();
				this->_data = new T[this->_size];
			}
			for (unsigned int i = 0; i < this->_size; i++)
				this->_data[i] = rhs[i];
		}
		return *this;
	}

	T &	operator[](unsigned int index) const{

		if (this->_data == NULL || index < 0 || index >= this->_size)
			throw std::out_of_range("out of range index");

		return this->_data[index];
	}

	unsigned int	size(void) const{

		return this->_size;
	}

private:

	T*				_data;
	unsigned int	_size;
};

#endif
