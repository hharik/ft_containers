#include "vector.hpp"
// #include "map.hpp"
// #include "stack.hpp"


#include <fstream>      // std::ofstream


int main()
{
	std::ofstream my_file;
	my_file.open("my_test_file");
	std::ofstream there_file;
	there_file.open("there_test_file");
	/*test the constructors */
	{
		 // constructors used in the same order as described above:
 		std::vector<int> first;                                // empty vector of ints
		std::vector<int> second (4,100);                       // four ints with value 100
		std::vector<int> third (second.begin(),second.end());  // iterating through second
		std::vector<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		there_file << "The contents of fifth are:";
		for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			there_file << ' ' << *it;
		there_file << '\n';
	}
	{
		 // constructors used in the same order as described above:
 		ft::vector<int> first;                                
		ft::vector<int> second (4,100);                       
		ft::vector<int> third (second.begin(),second.end()); 
		ft::vector<int> fourth (third);                       
		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		my_file << "The contents of fifth are:";
		for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			my_file << ' ' << *it;
		my_file << '\n';
	}
	/*test assign*/
	{
		std::vector<int> first;
		std::vector<int> second;
		std::vector<int> third;

		first.assign (7,100);             // 7 ints with a value of 100

		std::vector<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.

		there_file << "Size of first: " << int (first.size()) << '\n';
		there_file << "Size of second: " << int (second.size()) << '\n';
		there_file << "Size of third: " << int (third.size()) << '\n';
	}
	{
		ft::vector<int> first;
		ft::vector<int> second;
		ft::vector<int> third;

		first.assign (7,100);             // 7 ints with a value of 100

		ft::vector<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.

		my_file << "Size of first: " << int (first.size()) << '\n';
		my_file << "Size of second: " << int (second.size()) << '\n';
		my_file << "Size of third: " << int (third.size()) << '\n';
	}
	/* TEST AT */
	{
		std::vector<int> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;

		there_file << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			there_file << ' ' << myvector.at(i);
		there_file << '\n';
	}
	{
		ft::vector<int> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;

		my_file << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			my_file << ' ' << myvector.at(i);
		my_file << '\n';
	}
	/* VECTOR BACK */
	{
		std::vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1);
		}

		there_file << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			there_file << ' ' << myvector[i];
		there_file << '\n';
	}
	{
		ft::vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}

		my_file << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			my_file << ' ' << myvector[i];
		my_file << '\n';
	}
	/* ITERATOR begin */
	{
		std::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		there_file << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			there_file << ' ' << *it;
		there_file << '\n';
	}
	{
		ft::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		my_file << "myvector contains:";
		for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			my_file << ' ' << *it;
		my_file << '\n';
	}
	/*Capacity VECTOR */
	{
		std::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		there_file << "size: " << (int) myvector.size() << '\n';
		there_file << "capacity: " << (int) myvector.capacity() << '\n';
		there_file << "max_size: " << (int) myvector.max_size() << '\n';
	}
	{
		ft::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		my_file << "size: " << (int) myvector.size() << '\n';
		my_file << "capacity: " << (int) myvector.capacity() << '\n';
		my_file << "max_size: " << (int) myvector.max_size() << '\n';
	}
	/*CLEAR VECTOR */
	{
		std::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		there_file << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			there_file << ' ' << myvector[i];
		there_file << '\n';

		myvector.clear();
		myvector.push_back (1101);
		myvector.push_back (2202);

		there_file << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			there_file << ' ' << myvector[i];
		there_file << '\n';
	}
	{
		ft::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		my_file << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			my_file << ' ' << myvector[i];
		my_file << '\n';

		myvector.clear();
		myvector.push_back (1101);
		myvector.push_back (2202);

		my_file << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			my_file << ' ' << myvector[i];
		my_file << '\n';
	}
	/*EMPTY*/
	{
		std::vector<int> myvector;
		int sum (0);

		for (int i=1;i<=10;i++) myvector.push_back(i);

		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}
  		there_file << "total: " << sum << '\n';
	}
	{
		ft::vector<int> myvector;
		int sum (0);

		for (int i=1;i<=10;i++) myvector.push_back(i);

		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}
  		my_file << "total: " << sum << '\n';
	}
	/*END ITERATOR*/
	{
		std::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		there_file << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			there_file << ' ' << *it;
		there_file << '\n';
	}
	{
		ft::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		my_file << "myvector contains:";
		for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			my_file << ' ' << *it;
		my_file << '\n';
	}
	/* ERASE */
	{
		std::vector<int> myvector;

		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);

		// erase the 6th element
		myvector.erase (myvector.begin()+5);

		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);

		there_file << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			there_file << ' ' << myvector[i];
		there_file << '\n';
	}

	{
		ft::vector<int> myvector;

		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);

		// erase the 6th element
		myvector.erase (myvector.begin()+5);

		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);

		my_file << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			my_file << ' ' << myvector[i];
		my_file << '\n';
	}
	/*FRONT VECTOR*/
	{
		 std::vector<int> myvector;
		myvector.push_back(78);
		myvector.push_back(16);

		// now front equals 78, and back 16

		myvector.front() -= myvector.back();

	  there_file << "myvector.front() is now " << myvector.front() << '\n';
	}
	{
		 ft::vector<int> myvector;
		myvector.push_back(78);
		myvector.push_back(16);

		// now front equals 78, and back 16

		myvector.front() -= myvector.back();

	  my_file << "myvector.front() is now " << myvector.front() << '\n';
	}
	/*GET ALLOCATOR*/
	{
		std::vector<int> myvector;
		int * p;
		unsigned int i;

		// allocate an array with space for 5 elements using vector's allocator:
		p = myvector.get_allocator().allocate(5);

		// construct values in-place on the array:
		for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

		there_file << "The allocated array contains:";
		for (i=0; i<5; i++) there_file << ' ' << p[i];
		there_file << '\n';

		// destroy and deallocate:
		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
		myvector.get_allocator().deallocate(p,5);
	
	}
	{
		ft::vector<int> myvector;
		int * p;
		unsigned int i;

		// allocate an array with space for 5 elements using vector's allocator:
		p = myvector.get_allocator().allocate(5);

		// construct values in-place on the array:
		for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

		my_file << "The allocated array contains:";
		for (i=0; i<5; i++) my_file << ' ' << p[i];
		my_file << '\n';

		// destroy and deallocate:
		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
		myvector.get_allocator().deallocate(p,5);
	
	}
	/*INSERT VECTOR */
	{
		std::vector<int> myvector (3,100);
		std::vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert ( it , 200 );

		myvector.insert (it,2,300);

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		std::vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);

		there_file << "myvector contains:";
		for (it=myvector.begin(); it<myvector.end(); it++)
			there_file << ' ' << *it;
		there_file << '\n';
	}
	{
		ft::vector<int> myvector (3,100);
		ft::vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert ( it , 200 );

		myvector.insert (it,2,300);

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		ft::vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);

		my_file << "myvector contains:";
		for (it=myvector.begin(); it<myvector.end(); it++)
			 my_file << ' ' << *it;
		my_file << '\n';
	}
	/*MAX_SIZE VECTOR */
	{ 
		std::vector<int> myvector;
		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		there_file << "size: " << myvector.size() << "\n";
		there_file << "capacity: " << myvector.capacity() << "\n";
		there_file << "max_size: " << myvector.max_size() << "\n";

	}
	{ 
		ft::vector<int> myvector;
		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		my_file << "size: " << myvector.size() << "\n";
		my_file << "capacity: " << myvector.capacity() << "\n";
		my_file << "max_size: " << myvector.max_size() << "\n";
	}
	/*OPERATOR []*/	
	{
		std::vector<int> myvector (10);   // 10 zero-initialized elements

		std::vector<int>::size_type sz = myvector.size();

		// assign some values:
		for (unsigned i=0; i<sz; i++) myvector[i]=i;

		// reverse vector using operator[]:
		for (unsigned i=0; i<sz/2; i++)
		{
			int temp;
			temp = myvector[sz-1-i];
			myvector[sz-1-i]=myvector[i];
			myvector[i]=temp;
		}

		there_file << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			there_file << ' ' << myvector[i];
		there_file << '\n';
	}
	{
		ft::vector<int> myvector (10);   // 10 zero-initialized elements

		ft::vector<int>::size_type sz = myvector.size();

		// assign some values:
		for (unsigned i=0; i<sz; i++) myvector[i]=i;

		// reverse vector using operator[]:
		for (unsigned i=0; i<sz/2; i++)
		{
			int temp;
			temp = myvector[sz-1-i];
			myvector[sz-1-i]=myvector[i];
			myvector[i]=temp;
		}

		my_file << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			my_file << ' ' << myvector[i];
		my_file << '\n';
	}
	/*OPERATOR = VECTOR */
	{
		std::vector<int> foo (3,0);
		std::vector<int> bar (5,0);

		bar = foo;
		foo = std::vector<int>();

		there_file << "Size of foo: " << int(foo.size()) << '\n';
		there_file << "Size of bar: " << int(bar.size()) << '\n';
	}
	{
		ft::vector<int> foo (3,0);
		ft::vector<int> bar (5,0);

		bar = foo;
		foo = ft::vector<int>();

		my_file << "Size of foo: " << int(foo.size()) << '\n';
		my_file << "Size of bar: " << int(bar.size()) << '\n';
	}
	 /*POP_BACK VECTOR */
	 {
		std::vector<int> myvector;
		int sum (0);
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		while (!myvector.empty())
		{
			sum+=myvector.back();
			myvector.pop_back();
		}

		there_file << "The elements of myvector add up to " << sum << '\n';
	}
	{
		ft::vector<int> myvector;
		int sum (0);
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		while (!myvector.empty())
		{
			sum+=myvector.back();
			myvector.pop_back();
		}

		my_file << "The elements of myvector add up to " << sum << '\n';
	}
	/*PUSH_BACK VECTOR*/
	{
		std::vector<int> myvector;

		// there_file << "Please enter some integers (enter 0 to end):\n";
		int arr[] = {0,1,2,3,4,5,6,7, 52};
		for (int i = 0; i < 9; i++)
		{
			myvector.push_back(arr[i]);
		}

		there_file << "myvector stores " << int(myvector.size()) << " numbers.\n";
		there_file << "Container Contents: " << std::endl;
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			there_file << *it << " ";
		there_file << std::endl;
	}
	{
		ft::vector<int> myvector;

		// there_file << "Please enter some integers (enter 0 to end):\n";
		int arr[] = {0,1,2,3,4,5,6,7, 52};
		for (int i = 0; i < 9; i++)
		{
			myvector.push_back(arr[i]);
		}

		my_file << "myvector stores " << int(myvector.size()) << " numbers.\n";
		my_file << "Container Contents: " << std::endl;
		for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			my_file << *it << " ";
		my_file << std::endl;
	}
	/*RBEGIN */
	{
		std::vector<int> myvector (5);  // 5 default-constructed ints
		int i=0;

		std::vector<int>::reverse_iterator rit = myvector.rbegin();
		for (; rit!= myvector.rend(); ++rit)
			*rit = ++i;

		there_file << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			there_file << ' ' << *it;
		there_file << '\n';
	}
	{
		ft::vector<int> myvector (5);  // 5 default-constructed ints
		int i=0;

		ft::vector<int>::reverse_iterator rit = myvector.rbegin();
		for (; rit!= myvector.rend(); ++rit)
			*rit = ++i;

		my_file << "myvector contains:";
		for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			my_file << ' ' << *it;
		my_file << '\n';
	}
	/*REND VECTOR */
	{
		std::vector<int> myvector (5);  // 5 default-constructed ints

		std::vector<int>::reverse_iterator rit = myvector.rbegin();

		int i=0;
		for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
			*rit = ++i;

		there_file << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			there_file << ' ' << *it;
		there_file << '\n';
	}
	{
		ft::vector<int> myvector (5);  // 5 default-constructed ints
		ft::vector<int>::reverse_iterator rit = myvector.rbegin();

		int i=0;
		for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
			*rit = ++i;

		my_file << "myvector contains:";
		for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			my_file << ' ' << *it;
		my_file << '\n';
	}
	/*RESERVE _VECTOR */
	{
		std::vector<int>::size_type sz;
		std::vector<int> foo;
		sz = foo.capacity();
		there_file << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
			sz = foo.capacity();
			there_file << "capacity changed: " << sz << '\n';
			}
		}

		std::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		there_file << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
			sz = bar.capacity();
			there_file << "capacity changed: " << sz << '\n';
			}
		}
	}
	{
		ft::vector<int>::size_type sz;
		ft::vector<int> foo;
		sz = foo.capacity();
		my_file << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
			sz = foo.capacity();
			my_file << "capacity changed: " << sz << '\n';
			}
		}

		ft::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		my_file << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
			sz = bar.capacity();
			my_file << "capacity changed: " << sz << '\n';
			}
		}
	}
	/*RESIZE VECTOR */
	{
		std::vector<int> myvector;

		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);

		there_file << "myvector contains:";
		for (size_t i=0;i<myvector.size();i++)
			there_file << ' ' << myvector[i];
		there_file << '\n';
	}
	{
		ft::vector<int> myvector;

		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);

		my_file << "myvector contains:";
		for (size_t i=0;i<myvector.size();i++)
			my_file << ' ' << myvector[i];
		my_file << '\n';
	}
	/*SIZE VECTOR */
	{
		 std::vector<int> myints;
		there_file << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; i++) myints.push_back(i);
		there_file << "1. size: " << myints.size() << '\n';

		myints.insert (myints.end(),10,100);
		there_file << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		there_file << "3. size: " << myints.size() << '\n';

	}
	{
		 ft::vector<int> myints;
		my_file << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; i++) myints.push_back(i);
		my_file << "1. size: " << myints.size() << '\n';

		myints.insert (myints.end(),10,100);
		my_file << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		my_file << "3. size: " << myints.size() << '\n';
	}
	/*SWAP*/
	{
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		there_file << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			there_file << ' ' << foo[i];
		there_file << '\n';

		there_file << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			there_file << ' ' << bar[i];
		there_file << '\n';
	}
	{
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		my_file << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			my_file << ' ' << foo[i];
		my_file << '\n';

		my_file << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			my_file << ' ' << bar[i];
		my_file << '\n';

	}
	//RATIONAL OPERATORS
	{
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int> bar (2,200);   // two ints with a value of 200
		if (foo==bar) there_file << "foo and bar are equal\n";
		if (foo!=bar) there_file << "foo and bar are not equal\n";
		if (foo< bar) there_file << "foo is less than bar\n";
		if (foo> bar) there_file << "foo is greater than bar\n";
		if (foo<=bar) there_file << "foo is less than or equal to bar\n";
		if (foo>=bar) there_file << "foo is greater than or equal to bar\n";

	}
	{
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (2,200);   // two ints with a value of 200
		if (foo==bar) my_file << "foo and bar are equal\n";
		if (foo!=bar) my_file << "foo and bar are not equal\n";
		if (foo< bar) my_file << "foo is less than bar\n";
		if (foo> bar) my_file << "foo is greater than bar\n";
		if (foo<=bar) my_file << "foo is less than or equal to bar\n";
		if (foo>=bar) my_file << "foo is greater than or equal to bar\n";
	}
	/*SWAP NON MEMBER*/
	{
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		there_file << "foo contains:";
		for (std::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
			there_file << ' ' << *it;
		there_file << '\n';

		there_file << "bar contains:";
		for (std::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
			there_file << ' ' << *it;
		there_file << '\n';
	}
	{
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		my_file << "foo contains:";
		for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
			my_file << ' ' << *it;
		my_file << '\n';

		my_file << "bar contains:";
		for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
			my_file << ' ' << *it;
		my_file << '\n';
	}
}