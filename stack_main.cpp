#include "stack.hpp"
#include <fstream>      // std::ofstream


int main()
{
	std::ofstream mine;
	mine.open("my_test_file");
	std::ofstream there;
	there.open("there_test_file");
	//test STACK 
	/*CONSTRUCTOR*/
	{
		std::deque<int> mydeque (3,100);          // deque with 3 elements
		std::vector<int> myvector (2,200);        // vector with 2 elements

		std::stack<int> first;                    // empty stack
		std::stack<int, std::deque<int> > second (mydeque);         // stack initialized to copy of deque

		std::stack<int,std::vector<int> > third;  // empty stack using vector
		std::stack<int,std::vector<int> > fourth (myvector);

		there << "size of first: " << first.size() << '\n';
		there << "size of second: " << second.size() << '\n';
		there << "size of third: " << third.size() << '\n';
		there << "size of fourth: " << fourth.size() << '\n';
	}
	{
		std::deque<int> mydeque (3,100);          // deque with 3 elements
		ft::vector<int> myvector (2,200);        // vector with 2 elements

		ft::stack<int> first;                    // empty stack
		ft::stack<int, std::deque<int> > second (mydeque);         // stack initialized to copy of deque

		ft::stack<int,ft::vector<int> > third;  // empty stack using vector
		ft::stack<int,ft::vector<int> > fourth (myvector);

		mine << "size of first: " << first.size() << '\n';
		mine << "size of second: " << second.size() << '\n';
		mine << "size of third: " << third.size() << '\n';
		mine << "size of fourth: " << fourth.size() << '\n';
	}
	/*EMPTY*/
	{
		std::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
 	 	there << "total: " << sum << '\n';

	}
	{
		ft::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
 	 	mine << "total: " << sum << '\n';
	}
	/*POP STACK*/
	{
		std::stack<int> mystack;
		for (int i=0; i<5; ++i) mystack.push(i);

		there << "Popping out elements...";
		while (!mystack.empty())
		{
			there << ' ' << mystack.top();
			mystack.pop();
		}
		there << '\n';
	}
	{
		ft::stack<int> mystack;
		for (int i=0; i<5; ++i) mystack.push(i);

		mine << "Popping out elements...";
		while (!mystack.empty())
		{
			mine << ' ' << mystack.top();
			mystack.pop();
		}
		mine << '\n';
	}
	/*PUSH*/
	{
		std::stack<int> mystack;
		for (int i=0; i<5; ++i) mystack.push(i);

		there << "Popping out elements...";
		while (!mystack.empty())
		{
			there << ' ' << mystack.top();
			mystack.pop();
		}
		there << '\n';
	}
	{
		ft::stack<int> mystack;
		for (int i=0; i<5; ++i) mystack.push(i);

		mine << "Popping out elements...";
		while (!mystack.empty())
		{
			mine << ' ' << mystack.top();
			mystack.pop();
		}
		mine << '\n';
	}
	/*SIZE*/
	{
		std::stack<int> myints;
		there << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		there << "1. size: " << myints.size() << '\n';

		myints.pop();
		there << "2. size: " << myints.size() << '\n';

	}
	{
		ft::stack<int> myints;
		mine << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		mine << "1. size: " << myints.size() << '\n';

		myints.pop();
		mine << "2. size: " << myints.size() << '\n';
	}
	/*TOP */
	{
		std::stack<int> mystack;
		mystack.push(10);
		mystack.push(20);
		mystack.top() -= 5;
  		there << "mystack.top() is now " << mystack.top() << '\n';
	}
	{
		ft::stack<int> mystack;
		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		mine << "mystack.top() is now " << mystack.top() << '\n';
	}
	
}
