template < typename T, typename U, typename V >
void	iter(T* ptr, U len, void (*f)(V const &)){

	for (U i = 0; i < len; i++)
	{
		f(*ptr);
		ptr++;
	}
	return ;
}