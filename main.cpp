#include "vector.hpp"

int main()
{

		//testing relational operators
		// std::vector<int> foo (3,100);   // three ints with a value of 100
		// std::vector<int> bar (2,200);   // two ints with a value of 200

		// if (foo==bar) std::cout << "foo and bar are equal\n";
		// if (foo!=bar) std::cout << "foo and bar are not equal\n";
		// if (foo< bar) std::cout << "foo is less than bar\n";
		// if (foo> bar) std::cout << "foo is greater than bar\n";
		// if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		// if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	// std::vector <int> f(10, 5);
	// // std::vector <int> f;

	// ft::vector<int>::iterator it = f.begin();
	// std::cout << *it << std::endl;
	// ft::vector<int>::iterator end = f.end();
	// std::cout <<  *(end - 1)<< std::endl;
	// f.assign(f.begin(), f.end());
	// // ft::vector <int> fq(10, 5);
	// std::vector <int> f1;
	// ft::vector <int> f1(3, 100);
	// std::cout << "size and capacity > > " << f1.size() << " " << f1.capacity() << std::endl;
	// f1.insert(f1.begin(), 200);
	// f1.insert(f1.begin(), 2,300);
	// // f1.push_back(30);
	// // f1.push_back(40);
	// // f1.push_back(50);
	// // f1.push_back(60);
	// // f1.push_back(70);
	// // f1.push_back(80);

	// // f2.push_back(30);
	// // f2.push_back(40);
	// // f2.push_back(50);
	// // f2.push_back(60);
	// // f2.push_back(70);
	// // f2.push_back(80);
	// // for (int i = 0; i < f1.size(); i++)
	// // 	std::cout << " before VECTOR " << f1[i] << std::endl;
	// int myarray [] = { 501,502,503 };
	// // std::cout << std::endl;
	// // f1.insert(f1.begin(), myarray, myarray + 2);
	
	// std::cout << "size and capacity > > " << f1.size() << " " << f1.capacity() << std::endl;
	// for (int i = 0; i < f1.size(); i++)
	// 	std::cout << " AFTER VECTOR " << f1[i] << std::endl;
	
	// std::cout << "MY RESE" << std::endl;
	// std::cout << "size and capacity > > " << f2.size() << " " << f2.capacity() << std::endl;
	// f2.print();
	// f2.erase(f2.begin());

	// std::cout << "size and capacity > > " << f2.size() << " " << f2.capacity() << std::endl;
	// f2.print();

	// // for (int i = 0; i < f1.size(); i++)
	// std::cout << std::endl;
	// std::vector<int>::iterator it = f1.begin() + 1;
	// f2.assign(it, f1.end() - 1);
	// std::cout << "size and capacity > > " << f2.size() << " " << f2.capacity() << std::endl;
	// // f2.print();
	// for (int i = 0; i < f2.size(); i++)
	// 	std::cout << " > > " << f2[i] << std::endl;
	// ft::vector <int> f;
	// f.push_back(1);
    // f.push_back(2);
	// f.push_back(3);
	// f.push_back(5);
	// f.push_back(6);
	// f.push_back(7);
	// // for (int i = 0; i < f1.size() ; i++)
	// // {
	// // 	std::cout << &f1[i] << std::endl;
	// // }
	// f1 = f;
	// std::cout << "+++++++++++++++++++" << std::endl;
	// f1.print();
	// for (int i = 0; i < f1.size() ; i++)
	// {
	// 	std::cout << &f1[i] << std::endl;
	// }	// std::cout << "size and capacity > > " << f.size() << " " << f.capacity() << std::endl;
	
	// std::cout << std::endl;
	// f.insert(f.begin() + 5  , 20);
	// // // ft::vector<int>::iterator it = f.begin();
	// // ft::vector<int>::iterator iter = f.insert(f.begin(), 9);
	// std::cout << "size and capacity > > " << f.size() << " " << f.capacity() << std::endl;
	// f.print();
	// for (int i = 0; i < f.size(); i++)
	// f.resize(11, 9);
	// 	std::cout << " > > " << f[i] << std::endl;
	// // f.push_back(122);
	// std::cout << "size and capacity > > " << f.size() << " " << f.capacity() << std::endl;
	// for (int i = 0; i < f.size(); i++)
	// 	std::cout << " > > " << f[i] << std::endl;
	// std::cout << std::endl;
	
	// // f.assign(5, 6);
	// std::cout << "MINE size and capacity > > " << fq.size() << " " << f.capacity() << std::endl;

	// fq.print();
	// std::cout << std::endl;
	// fq.resize(11, 9);
	// // fq.push_back(122);
	// std::cout << "MINE size and capacity > > " << fq.size() << " " << f.capacity() << std::endl;

	// std::cout << "size and capacity > > " << f.size() << " " << f.capacity() << std::endl;
	// // for (int i = 0; i < f.size(); i++)
	// // 	std::cout << " > > " << f[i] << std::endl;

	// fq.print();
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