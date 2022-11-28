// #include "vector.hpp"
#include <iostream>
#include <vector>

// #include <cstddef>
// #include <sstream>
// #include "struct_utils.hpp"
#include <algorithm>

// class conv_clas{
// 	public:
// 	int nb;
// 		conv_clas(){}
// 		conv_clas(int a):nb(a) {}
// 		operator int (){return nb;}
// };

	// int b = 0;
	// std::cout<<"b before"<<b<<std::endl;
	// conv_clas cv = 9;
	// b = cv;
	// std::cout<<"b after"<<b<<std::endl;
 std::string s_string[32] = {                                                                   \
        "QExoqp0nICr0sXsHqty2", "naax9QcpJhvaL7DezsNQ", "25ZTtB6wbptfbxM8AvHB",                    \
        "tShYNtc0MkdjqLrOatgz", "7Z3kf1Qec0NnsLSEpbOt", "WhkSNrKJC966fvjZ2Or1",                    \
        "8vlxlFRRgW7yYj4GO7dt", "5sq1aoT8zP0HaHj3nFOK", "61Dv31GYZhkgjKCErpng",                    \
        "l0IIcWWHhOcPzoxEamQM", "bE1RYclskwXlhCm46YFs", "kXeoi5qz94JYPqSDTs79",                    \
        "TFsQP1dz8VVos9KzUpY0", "b3wYQR7An193gjgYuRj3", "xSmyNsnSJ47jLqrvbpyr",                    \
        "guAIP2Wq43Gf8VhHsyu5", "yT6c2loPebHovnq9BQog", "3qvU1xcVm2g1DKFDlqh4",                    \
        "L0q8RR9P41VD4sVjdnWl", "YdjESsIZM4b1oGQPjpBe", "l1ZVQbWKw7brHUSimJgq",                    \
        "xdn0cf4vqRzpfXWtl10G", "lYnZvpqaV0s8DowMZwzV", "8P1cyKrwJNLoJyvLjYqO",                    \
        "4MhOXNbAX23CEijO5cRT", "tHe3miAwCOVQbuoLaEP2", "l6uNLsc8fiLl3eWoG6j6",                    \
        "477xt6l0lph9ALQdr4HX", "D9UJNe4s8YF02LhrwOdl", "dLCisBNOdE8yugntu6cj",                    \
        "YvY4aQFHgAuagn4dFLO1", "eGR6Dtv7LW75qlV5Fkik"                                             \
    };                                                                
	 std::string b_string[64] = {                                                                   \
        "uvg6KqtcgduR31n3ajsv", "wbiAcjgojb9JOagZwyMn", "ATZKCzaPOqgkhPjwuGlf",                    \
        "MOhaJs56yjOw8f6nLPRA", "0gyB2Tr42v6awMw2nK7J", "e6GsiLFUuoDpVFEhJKZ1",                    \
        "z0jXAhiV9keBsaLOY0Xf", "P68p2ZAosHJdmoZh1C7N", "Pu3EuZVeY0TCO3ojdK0t",                    \
        "z7jCHMooHCS73M8GygKB", "uT4KoK83JrZxZjkul7ty", "g8gfrZoY5XwfzRusvHvv",                    \
        "7PGmkM0OSRnYREt9mFIP", "q1od7mBIpPEsCtpF9kdw", "XQo0LWId5TdZnLnpUNOb",                    \
        "U0m1R0kFFhAFyS6hmHHw", "K0lPKfxJxIOnE8QB90xn", "cZ5xyQifMJhrKxqBK9A7",                    \
        "cFBiwjfYw7Js6qEGy5Kt", "1tW0KWfXxeFO69tByqcE", "3Fvq9NxBrhPXHe0IlIVx",                    \
        "MSRDjdFRvHAhFGhiMtDe", "zGm2joMh71jQkYzg5L4V", "Mq4RRaeLvSAO0z2ibp8Q",                    \
        "WnLFYnQKP8TNJkqVVbUg", "E98UphbbVSzrW5Mzurmg", "F8HRxeEcaTZDkFPkioij",                    \
        "jmUVl4Q8X5BwVNzXN219", "n7Xp4w4FwzGKit7AI4SO", "4MxXYr6rKOcXLt9UkVd2",                    \
        "4RVTDsADtRyboaai9d29", "XaSqsrrtdhAfFoJIc5KK", "9Z9jdVCrTT09bg348ceb",                    \
        "I6uqLG9dO5mfNdSMwOYm", "UwMTzJPlbnhgwbHpDi6w", "DebjMP9afncYE6GhhO00",                    \
        "YGPuscYDiGfAjY1UWST0", "K6gbvgGjVZgEFUDlkdSk", "8xCBPI0w6TpC0RA62c2W",                    \
        "fYMxkNwmKg3moP8KvD9v", "QpPdhwhEYjIugg3OPcPH", "qQBXjSn43I3EMP54SyxZ",                    \
        "7qvdKwoW1CQEZTWPvuSC", "rCT212rdYO0zTGHXesKg", "dBHvlHsBwcR9MkkenYYG",                    \
        "NQiSlergqR8fVbOeivLj", "xYVqsV147UIe7jVBVwXo", "tcxayO4DdEJ885TbqUMy",                    \
        "9TGSMTD8U8ksRpHqq0cL", "TIJ16jCv9BSUiWvhbF9T", "BM9GL2ig1hePkA6lM6Ck",                    \
        "TfJTYB9JQMU6CGcYg20Q", "Fg6e5YT2FQbpTZNTDqdo", "LI5q6ml40MeE9H1dPb93",                    \
        "OaxJUSm3nYN9Y8Ela7sS", "BgBeODAwXz7xJo50Rwqd", "xdkgKj1dEoJ6zuVhkvvo",                    \
        "olIewtUEvXJgs1lB9bCn", "dTsPDS0x2uXtcgOIJHb8", "DYvJ2phLppGNZKboTBrd",                    \
        "DjNFMtt9PxkzqvWBHI6j", "1Z3YkeTFlPniKnzFhzgu", "76XqQg6hqMf5IXxKPOEs",                    \
        "gzaapTWW7i9EZjjzLeK6"                                                                     \
    };

int main()
{
	char foo[]="Apple";
  	char bar[]="Apple";

 	std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+5);






	// std::cout << "<int> " << ft::is_integral<double>::value << std::endl;
  	// ft::vector<int> myvector;
	// for (int i=1; i<=10; i++) myvector.push_back(i);
	// for (ft::vector<int>::iterator r = myvector.begin(); r != myvector.end(); r++)
	// 	std::cout << *r << " ";
	// std::cout << std::endl;
 	// myvector.erase (myvector.begin(),myvector.begin()+3);
	// for (ft::vector<int>::iterator r = myvector.begin(); r != myvector.end(); r++)
	// 	std::cout << *r << " ";

//    std::istringstream str("12345"); // push_back //input_iterator_tag
//     std::istreambuf_iterator<char> it(str), end;
// 	ft::vector <char> v(it, end);
// 	std::cout << "v1 size and capacity > > " << v.size() << " " << v.capacity() << std::endl;
// 	for (ft::vector<char>::iterator r = v.begin(); r != v.end(); r++)
// 		std::cout << *r;
// 	std::cout << " ************** " << std::endl;

// 	std::string str1 = "Hello world!"; // len // forward_iterator_tag
// 	ft::vector<char> v1(str1.begin(), str1.end());
// 	std::cout << "v1 size and capacity > > " << v1.size() << " " << v1.capacity() << std::endl;


	// std::cout << "THERESS : " << std::vector<unsigned char>().max_size() << std::endl;
	// std::cout <<" MINE : " << ft::vector<unsigned char>().max_size() << std::endl;
	// std::cout << "THERESS : " << std::vector<char>().max_size() << std::endl;
	// std::cout <<" MINE : " << ft::vector<char>().max_size() << std::endl;
	// std::cout << "THERESS : " << std::vector<int>().max_size() << std::endl;
	// std::cout <<" MINE : " << ft::vector<int>().max_size() << std::endl;
	// std::cout << "THERESS : " << std::vector<long>().max_size() << std::endl;
	// std::cout <<" MINE : " << ft::vector<long>().max_size() << std::endl;
	// ft::vector <std::string> v;
	// v.resize(14, "helloWorld");
	// v.resize(6, "ABC");
	// v.resize(14, b_string[18]);
	// v.resize(15, b_string[57]);

	// // v.resize(64, "I-like-vectors");
	






	// std::size_t b_size = 64; 
	// std::size_t s_size = 32;
	// ft::vector <std::string> v;
	// v.insert(v.begin(), v.begin(), v.begin());
	// v.insert(v.begin(), v.begin(), v.end());
	// v.insert(v.end(), v.begin(), v.end());
	// v.insert(v.begin(), s_string, s_string + s_size);
	// v.insert(v.begin(), b_string, b_string + 10);
	// v.insert(v.begin() + 20, b_string, b_string + b_size);


	// ft::vector<std::string> v;
 	// v.insert(v.begin() + 115, (std::size_t)std::numeric_limits<std::ptrdiff_t>::max(),"123");
	// // v.insert(v.begin(), 0, 64);
	// // v.insert(v.end(), 0, 64);
	// // v.insert(v.end(), 10, 64);
	// // v.insert(v.begin(), 5, -1);
	// // v.insert(v.begin() + 1, 1, -9);
	// // v.insert(v.begin() + 7, 21, 88);
	// // v.insert(v.begin(), 0, 2);
	// // v.insert(v.end(), 0, 4);
	// // v.insert(v.end(), 18, 420);
	// std::cout << "v1 size and capacity > > " << v.size() << " " << v.capacity() << std::endl;
	// for (ft::vector<std::string>::iterator r = v.begin(); r != v.end(); r++)
	// 	std::cout << *r << std::endl;
	
	



	// std::cout <<b_string[54] << std::endl;
	// ft::vector <std::string> v;
	// ft::vector <std::string>::iterator	it = v.insert(v.end(), b_string[54]);
	// std::cout << " ******************************** " << std::endl;
	// it = v.insert(v.end(), b_string[23]);
	// for (ft::vector<std::string>::iterator r = v.begin(); r != v.end(); r++)
	// 	std::cout << *r << std::endl;
	// std::cout << " ******************************** " << std::endl;
	// std::cout << "v1 size and capacity > > " << v.size() << " " << v.capacity() << std::endl;

	// std::vector<std::string> ar(1, "hello world");
	// for (std::vector<std::string>::iterator it = ar.begin(); it != ar.end(); it++)
	// 		std::cout << *it << " ";
	// std::cout << std::endl;
	// std::cout << "v1 size and capacity > > " << ar.size() << " " << ar.capacity() << std::endl;
	// ar.erase(ar.begin() );
	// for (std::vector<std::string>::iterator it = ar.begin(); it != ar.end(); it++)
	// 		std::cout << *it << " ";
	// std::cout << "v1 size and capacity > > " << ar.size() << " " << ar.capacity() << std::endl;
	// ft::vector<std::string> v1;
	// std::vector<std::string> v2(2, "hello world");

	// for (std::vector<std::string>::iterator it = v2.begin(); it != v2.end(); ++it)
	// 	std::cout << *it << std::endl;
	// std::size_t b_size = 64;   
	// std::string b_string[64] = {                                                                   \
    //     "uvg6KqtcgduR31n3ajsv", "wbiAcjgojb9JOagZwyMn", "ATZKCzaPOqgkhPjwuGlf",                    \
    //     "MOhaJs56yjOw8f6nLPRA", "0gyB2Tr42v6awMw2nK7J", "e6GsiLFUuoDpVFEhJKZ1",                    \
    //     "z0jXAhiV9keBsaLOY0Xf", "P68p2ZAosHJdmoZh1C7N", "Pu3EuZVeY0TCO3ojdK0t",                    \
    //     "z7jCHMooHCS73M8GygKB", "uT4KoK83JrZxZjkul7ty", "g8gfrZoY5XwfzRusvHvv",                    \
    //     "7PGmkM0OSRnYREt9mFIP", "q1od7mBIpPEsCtpF9kdw", "XQo0LWId5TdZnLnpUNOb",                    \
    //     "U0m1R0kFFhAFyS6hmHHw", "K0lPKfxJxIOnE8QB90xn", "cZ5xyQifMJhrKxqBK9A7",                    \
    //     "cFBiwjfYw7Js6qEGy5Kt", "1tW0KWfXxeFO69tByqcE", "3Fvq9NxBrhPXHe0IlIVx",                    \
    //     "MSRDjdFRvHAhFGhiMtDe", "zGm2joMh71jQkYzg5L4V", "Mq4RRaeLvSAO0z2ibp8Q",                    \
    //     "WnLFYnQKP8TNJkqVVbUg", "E98UphbbVSzrW5Mzurmg", "F8HRxeEcaTZDkFPkioij",                    \
    //     "jmUVl4Q8X5BwVNzXN219", "n7Xp4w4FwzGKit7AI4SO", "4MxXYr6rKOcXLt9UkVd2",                    \
    //     "4RVTDsADtRyboaai9d29", "XaSqsrrtdhAfFoJIc5KK", "9Z9jdVCrTT09bg348ceb",                    \
    //     "I6uqLG9dO5mfNdSMwOYm", "UwMTzJPlbnhgwbHpDi6w", "DebjMP9afncYE6GhhO00",                    \
    //     "YGPuscYDiGfAjY1UWST0", "K6gbvgGjVZgEFUDlkdSk", "8xCBPI0w6TpC0RA62c2W",                    \
    //     "fYMxkNwmKg3moP8KvD9v", "QpPdhwhEYjIugg3OPcPH", "qQBXjSn43I3EMP54SyxZ",                    \
    //     "7qvdKwoW1CQEZTWPvuSC", "rCT212rdYO0zTGHXesKg", "dBHvlHsBwcR9MkkenYYG",                    \
    //     "NQiSlergqR8fVbOeivLj", "xYVqsV147UIe7jVBVwXo", "tcxayO4DdEJ885TbqUMy",                    \
    //     "9TGSMTD8U8ksRpHqq0cL", "TIJ16jCv9BSUiWvhbF9T", "BM9GL2ig1hePkA6lM6Ck",                    \
    //     "TfJTYB9JQMU6CGcYg20Q", "Fg6e5YT2FQbpTZNTDqdo", "LI5q6ml40MeE9H1dPb93",                    \
    //     "OaxJUSm3nYN9Y8Ela7sS", "BgBeODAwXz7xJo50Rwqd", "xdkgKj1dEoJ6zuVhkvvo",                    \
    //     "olIewtUEvXJgs1lB9bCn", "dTsPDS0x2uXtcgOIJHb8", "DYvJ2phLppGNZKboTBrd",                    \
    //     "DjNFMtt9PxkzqvWBHI6j", "1Z3YkeTFlPniKnzFhzgu", "76XqQg6hqMf5IXxKPOEs",                    \
    //     "gzaapTWW7i9EZjjzLeK6"                                                                     \
	// };
	// // v1 = v2;
	// std::vector<std::string> v1(b_string, b_string + b_size);
	// v2 = v1;
	// for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it)
	// 	std::cout << *it << std::endl;
	// std::cout << v1.size() << std::endl;
	// ft::vector <char>  v;
	// std::istringstream str("1 2 3 4 5 6 7");
    // std::istreambuf_iterator<char> it(str), end;
	
	// v.assign(it, end);
	// std::cout << "size and capacity > > " << v.size() << " " << v.capacity() << std::endl;
	// for (ft::vector<char>::iterator i = v.begin(); i != v.end(); i++)
	// 		std::cout << " " <<  *i ;
	
	// ft::vector <char> v;
	// char tab[3] = { 'a', 'b','r'};
	// v.assign(tab, tab + 2);
	// std::cout << "size and capacity > > " << v.size() << " " << v.capacity() << std::endl;


	// std::cout << std::endl <<  "//********************************************** STD\\" << std::endl;
	// std::vector <char> v1;
	// std::cout << "size and capacity > > " << v1.size() << " " << v1.capacity() << std::endl;
	// v1.assign(tab, tab + 2);
	// std::cout << "size and capacity > > " << v1.size() << " " << v1.capacity() << std::endl;

	// for (std::vector<char>::iterator i = v1.begin(); i != v1.end(); i++)
	// 		std::cout << " " <<  *i  ;
	// int number [] = {1, 2, 6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};
	// // ft::Vector<int> second (4,100);                       
	// ft::vector<int> third(2, 3);
	// third.push_back(5);
	// // third.push_back(10);

	// // third.insert(third.begin(), number, number + 15);
	// // // ft::vector<int>::const_reverse_iterator it = myvector.rend() - 1;
	// // int myarray[] = {251, 5, 89};
	// 	// myvector.insert(myvector.begin(), myarray, myarray + 2);
	// std::cout << third.back();
	// for (ft::vector<int>::iterator it = third.begin()  ; it != third.end(); ++it)
	// 	std::cout << *(it) << std::endl;
	// ft::vector<int>::iterator it;

	// it = myvector.begin();
	// it = myvector.insert ( it , 200 );

	// myvector.insert (it,2,300);

	// "it" no longer valid, get a new one:
	// it = myvector.begin();

	// ft::vector<int> anothervector (2,400);
	// myvector.insert (it+2,anothervector.begin(),anothervector.end());

	// int myarray [] = { 501,502,503 };
	// myvector.insert (myvector.begin(), myarray, myarray+3);
	// std::cout<< *(myarray + 1)<<std::endl;
	// std::cout << "myvector contains:";
	// for (it=myvector.begin(); it<myvector.end(); it++)
		// std::cout << ' ' << *it;
	// std::cout << '\n';

	// for (ft::vector<int>::reverse_iterator iter = vec.rbegin(); iter != vec.rend(); ++iter) 
	// std::cout << " >> " << *(vec.rbegin() - 1) << " r_end << " << *(vec.rend()) << std::endl;
	// for (ft::vector <int>::iterator it = vec.begin(); it != vec.end(); it++) 
	// 	std::cout << *it << std::endl;
	// 	{
	// 		std::cout << *iter << std::endl;
	// 	}
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