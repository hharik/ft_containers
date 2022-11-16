#include "vector.hpp"


int main()
{
	ft::vector <int> f(10, 5);
	// std::vector <int> g(2, 10);
	std::cout << "size and capacity > > " << f.size() << " " << f.capacity() << std::endl;
	f.print();

	// for (int i = 0; i < f.size(); i++)
	// 	std::cout << " > > " << f[i] << std::endl;
	std::cout << std::endl;

	f.assign(5, 6);
	std::cout << "size and capacity > > " << f.size() << " " << f.capacity() << std::endl;
	// for (int i = 0; i < f.size(); i++)
	// 	std::cout << " > > " << f[i] << std::endl;
	f.print();

	// f.print();
	// g.print();
	// std::cout << " ___________________ " << std::endl;
	// f.swap(g);
	// // std::vector <int> s(5, 10);
	// // std::cout << " size " << f.size() << " resireve " << f.capacity()  << std::endl;
	// // f.swap(s);
	// // std::cout << " size " << f.size() << " resireve " << f.capacity()  << std::endl;
	// // f.clear();
	// f.print();
	// std::cout << std::endl;
	// g.print();
	// for (int i = 0; i < f.size(); i++)
	// 	std::cout << " > > " << f[i] << std::endl;
	// std::cout << std::endl;
	// for (int i = 0; i < s.size(); i++)
	// 	std::cout << " > > " << s[i] << std::endl;
	// f.push_back(1);
    // f.push_back(2);
	// f.pop_back();
	// ft::vector <int> d;
	// d.push_back(541);
	// d.push_back(546);
	// // for (int i = 0; i < d.size(); i++)
	// // 	std::cout << d[i] << std::endl;
	// // d.pop_back();
	// // std::cout << "size and capacity > > " << d.size() << " " << d.capacity() << std::endl;
	// // for (int i = 0; i < d.size(); i++)
	// // 	std::cout << &d[i] << std::endl;
	// d = f;
	// // for (int i = 0; i < d.size(); i++)
	// // 	std::cout << &d[i] << std::endl;
	
	// // // std::vector<int> f;
	// // std::cout << f.capacity();
	// // std::cout << f.size()  << " F "  << f.capacity() << std::endl;
	// // // // std::cout << " -               ---- " << std::endl;
	// // // // for (int i = 0; i < 10; i++)
	// // // // 	std::cout << f[i] << std::endl;
	// // std::cout << " ---- " << std::endl;
	// // // d.reserve(4);
	// // std::cout << d.size()  << " D "  << d.capacity() << std::endl;
	// // d.print();
	// // for (int i = 0; i < d.size(); i++)
	// 	std::cout << d[i] << std::endl;
}