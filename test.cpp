#include <type_traits>
#include <iostream>
#include <utility>
#include <vector>
template<typename T>
void foo(T)
{
	std::cout << "is signed" << std::endl;
}


// template <typename T, class = typename std::enable_if<std::is_unsigned<T>::value>::type>
// void	foo(T)
// {
// 	std::cout << "is unsinged" << std::endl;
// }
class test {
	protected: 
		test(std::string name): name(name) {std::cout << "Name " <<  name << std::endl;} 
		std::string name;
};

class Hamid : public test {
	int x;
	int y;

	// std::ostrea÷m obje;
public:
	//std::ostream(){}
	Hamid():x(10), y(10), test("urmom!")
	{
		std::cout << "hamid" << std::endl;
	}
	void	status()
	{
		std::cout << "x : " << x << std::endl;
		std::cout << "y : " << y << std::endl;
		// std::cout << "name : " << name << std::endl;
	}
// 	Hamid operator=(const Hamid& other)
// 	{

// 	}
};

std::pair<std::string, std::string>

int main()
{
	// unsigned int q = 5;
	// foo(q);
	char *str;
	Hamid hamid;
	char **temp;
	// std::cout << sizeof(hamid);
	str = (char *)&hamid;
	int *px = (int *)str;
	int *py = (int *)(str + 4);
	*px = 155;
	*py = -100;
	temp = (char**)(str + 8);
	// temp = (char **)&(hamid);
	// str = (char *)(str[0]);
	// hamid.status();

}