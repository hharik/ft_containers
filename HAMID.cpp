#include <iostream>

int ge(int &x)
{
	return (x);
}

template<class T> struct smiya{};

template<class T> struct smiya<T*>{};

template<class T> struct smiya<T&>{};


/*template <class T>*/  class t{
	public:
	t(smiya<int>){std::cout<<"smiya lowla khdmat\n";}
	t(smiya<int*>){std::cout<<"smiya tanya khdmat\n";}
	t(smiya<int&>){std::cout<<"smiya  tlata khdmat\n";}
};

int main()
{
	
}

