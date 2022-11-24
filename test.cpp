#include <type_traits>
#include <iostream>
#include <vector>
template<typename T>
void foo(T)
{
	std::cout << "is signed" << std::endl;
}


template <typename T, class = typename std::enable_if<std::is_unsigned<T>::value>::type>
void	foo(T)
{
	std::cout << "is unsinged" << std::endl;
}


int main()
{
	unsigned int q = 5;
	foo(q);
}