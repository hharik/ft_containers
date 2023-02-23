#include "map.hpp"
#include <fstream>      // std::ofstream
bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main() { 
	std::ofstream mine;
	mine.open("my_test_file");
	std::ofstream there;
	there.open("there_test_file");	
	/*TEST MAP*/
	{
		std::map<char,int> first;

		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;

		std::map<char,int> second (first.begin(),first.end());

		std::map<char,int> third (second);

		std::map<char,int,classcomp> fourth;                 // class as Compare

		bool(*fn_pt)(char,char) = fncomp;
		std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
		//The code does not produce any output, but demonstrates some ways in which a map container can be constructed.
	}
	/*TEST MAP*/
	{
		ft::map<char,int> first;

		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;

		ft::map<char,int> second (first.begin(),first.end());

		ft::map<char,int> third (second);

		ft::map<char,int,classcomp> fourth;                 // class as Compare

		bool(*fn_pt)(char,char) = fncomp;
		ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
		//The code does not produce any output, but demonstrates some ways in which a map container can be constructed.
	}
	/*BEGIN */
	{
		std::map<char,int> mymap;
		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;

		// show content:
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			there << it->first << " => " << it->second << '\n';
	}
	{
		ft::map<char,int> mymap;
		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;

		// show content:
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			mine << it->first << " => " << it->second << '\n';
	}
	/*clear*/
	{
		std::map<char,int> mymap;
		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;

		there << "mymap contains:\n";
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			there << it->first << " => " << it->second << '\n';

		mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;

		there << "mymap contains:\n";
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			there << it->first << " => " << it->second << '\n';
	}

	{
		ft::map<char,int> mymap;
		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;

		mine << "mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			mine << it->first << " => " << it->second << '\n';

		mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;

		mine << "mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			mine << it->first << " => " << it->second << '\n';
	}
	/*COUNT*/
	{ 
		std::map<char,int> mymap;
		char c;
		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;

		for (c='a'; c<'h'; c++)
		{
			there << c;
			if (mymap.count(c)>0)
			there << " is an element of mymap.\n";
			else 
			there << " is not an element of mymap.\n";
		}
	}
	{ 
		ft::map<char,int> mymap;
		char c;
		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;

		for (c='a'; c<'h'; c++)
		{
			mine << c;
			if (mymap.count(c)>0)
			mine << " is an element of mymap.\n";
			else 
			mine << " is not an element of mymap.\n";
		}
	}
	/*EMPTY*/
	{
		std::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		while (!mymap.empty())
		{
			there << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}
	}
	{
		ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		while (!mymap.empty())
		{
			mine << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}	
	}
	/*END ITERATOR MAPO*/
	{
		std::map<char,int> mymap;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;

		// show content:
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		    there << it->first << " => " << it->second << '\n';
	}
	{
		ft::map<char,int> mymap;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;

		// show content:
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			mine << it->first << " => " << it->second << '\n';
	}
	/*EQUAL RANGE*/
	{
		std::map<char,int> mymap;
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		there << "lower bound points to: ";
		there << ret.first->first << " => " << ret.first->second << '\n';

		there << "upper bound points to: ";
		there << ret.second->first << " => " << ret.second->second << '\n';
	}
	{
		ft::map<char,int> mymap;
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		mine << "lower bound points to: ";
		mine << ret.first->first << " => " << ret.first->second << '\n';

		mine << "upper bound points to: ";
		mine << ret.second->first << " => " << ret.second->second << '\n';
	}
	/*ERASE */
	{
		std::map<char,int> mymap;
		std::map<char,int>::iterator it;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator

		mymap.erase ('c');                  // erasing by key

		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range

		// show content:
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			there << it->first << " => " << it->second << '\n';

	}
	{
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator

		mymap.erase ('c');                  // erasing by key

		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range

		// show content:
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			mine << it->first << " => " << it->second << '\n';
	}
	/*FIND*/
	{
		std::map<char,int> mymap;
		std::map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);

		// print content:
		there << "elements in mymap:" << '\n';
		there << "a => " << mymap.find('a')->second << '\n';
		there << "c => " << mymap.find('c')->second << '\n';
		there << "d => " << mymap.find('d')->second << '\n';
	}
	{
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);

		// print content:
		mine << "elements in mymap:" << '\n';
		mine << "a => " << mymap.find('a')->second << '\n';
		mine << "c => " << mymap.find('c')->second << '\n';
		mine << "d => " << mymap.find('d')->second << '\n';
	}
	/*GET ALLOCATOR*/
	{
		 int psize;
		std::map<char,int> mymap;
		std::pair<const char,int>* p;

		// allocate an array of 5 elements using mymap's allocator:
		p=mymap.get_allocator().allocate(5);

		// assign some values to array
		psize = sizeof(std::map<char,int>::value_type)*5;

		there << "The allocated array has a size of " << psize << " bytes.\n";

		mymap.get_allocator().deallocate(p,5);
	}
	{
		int psize;
		ft::map<char,int> mymap;
		ft::pair<const char,int>* p;

		// allocate an array of 5 elements using mymap's allocator:
		p=mymap.get_allocator().allocate(5);

		// assign some values to array
		psize = sizeof(std::map<char,int>::value_type)*5;

		mine << "The allocated array has a size of " << psize << " bytes.\n";

		mymap.get_allocator().deallocate(p,5);
	}
	/*INSERT */
	{
		std::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( std::pair<char,int>('a',100) );
		mymap.insert ( std::pair<char,int>('z',200) );

		std::pair<std::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( std::pair<char,int>('z',500) );
		if (ret.second==false) {
			there << "element 'z' already existed";
			there << " with a value of " << ret.first->second << '\n';
		}

		// second insert function version (with hint position):
		std::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

		// third insert function version (range insertion):
		std::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		there << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			there << it->first << " => " << it->second << '\n';

		there << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			there << it->first << " => " << it->second << '\n';
	}
	{
		ft::map<char,int> mymap;
		// first insert function version (single parameter):
		mymap.insert ( ft::pair<char,int>('a',100) );
		mymap.insert ( ft::pair<char,int>('z',200) );

		ft::pair<ft::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( ft::pair<char,int>('z',500) );
		if (ret.second==false) {
			mine << "element 'z' already existed";
			mine << " with a value of " << ret.first->second << '\n';
		}

		// second insert function version (with hint position):
		ft::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

		// third insert function version (range insertion):
		ft::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		mine << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			mine << it->first << " => " << it->second << '\n';

		mine << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			mine << it->first << " => " << it->second << '\n';
	}
	/*KEY_COMP*/
		{
	std::map<char,int> mymap;
	std::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	there << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	std::map<char,int>::iterator it = mymap.begin();
	do {
		there << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	there << '\n';

	}
	{
		ft::map<char,int> mymap;
		ft::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;

		mine << "mymap contains:\n";

		char highest = mymap.rbegin()->first;     // key value of last element

		ft::map<char,int>::iterator it = mymap.begin();
		do {
			mine << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );

		mine << '\n';
	}	
	/*LOWER_BOUND*/
	{
		std::map<char,int> mymap;
		std::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			there << it->first << " => " << it->second << '\n';
	}
	{
				ft::map<char,int> mymap;
		ft::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			mine << it->first << " => " << it->second << '\n';
	}
	/*MAX_SIZE*/
	{
		int i;
		std::map<int,int> mymap;

		if (mymap.max_size()>1000)
		{
			for (i=0; i<1000; i++) mymap[i]=0;
			there << "The map contains 1000 elements.\n";
		}
		else there << "The map could not hold 1000 elements.\n";
	}
	{
		int i;
		ft::map<int,int> mymap;

		if (mymap.max_size()>1000)
		{
			for (i=0; i<1000; i++) mymap[i]=0;
			mine << "The map contains 1000 elements.\n";
		}
		else mine << "The map could not hold 1000 elements.\n";
	}
	/*OPERATOR []*/
	{
		std::map<char,std::string> mymap;
		mymap['a']="an element";
		mymap['b']="another element";
		mymap['c']=mymap['b'];

		there << "mymap['a'] is " << mymap['a'] << '\n';
		there << "mymap['b'] is " << mymap['b'] << '\n';
		there << "mymap['c'] is " << mymap['c'] << '\n';
		there << "mymap['d'] is " << mymap['d'] << '\n';

		there << "mymap now contains " << mymap.size() << " elements.\n";
	}
	{
		ft::map<char,std::string> mymap;
		mymap['a']="an element";
		mymap['b']="another element";
		mymap['c']=mymap['b'];

		mine << "mymap['a'] is " << mymap['a'] << '\n';
		mine << "mymap['b'] is " << mymap['b'] << '\n';
		mine << "mymap['c'] is " << mymap['c'] << '\n';
		mine << "mymap['d'] is " << mymap['d'] << '\n';

		mine << "mymap now contains " << mymap.size() << " elements.\n";
	}
	/*operator = */
	{
		std::map<char,int> first;
		std::map<char,int> second;

		first['x']=8;
		first['y']=16;
		first['z']=32;

		second=first;                // second now contains 3 ints
		first=std::map<char,int>();  // and first is now empty

		there << "Size of first: " << first.size() << '\n';
		there << "Size of second: " << second.size() << '\n';
	}
	{
		ft::map<char,int> first;
		ft::map<char,int> second;

		first['x']=8;
		first['y']=16;
		first['z']=32;

		second=first;                // second now contains 3 ints
		first=ft::map<char,int>();  // and first is now empty

		mine << "Size of first: " << first.size() << '\n';
		mine << "Size of second: " << second.size() << '\n';
	}
	/*RBEGIN*/
	{
		std::map<char,int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		// show content:
		std::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			there << rit->first << " => " << rit->second << '\n';
	}	
	{
		ft::map<char,int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		// show content:
		ft::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		 	mine<< rit->first << " => " << rit->second << '\n';
	}
	/*REND*/
	{
		std::map<char,int> mymap;
		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		// show content:
		std::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			there << rit->first << " => " << rit->second << '\n';
	}
	{
		ft::map<char,int> mymap;
		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		// show content:
		ft::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			mine << rit->first << " => " << rit->second << '\n';
	}
	/*SIZE */
	{
		std::map<char,int> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;

		 there << "mymap.size() is " << mymap.size() << '\n';

	}
	{
		ft::map<char,int> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;

		 mine << "mymap.size() is " << mymap.size() << '\n';
	}
	/*swap */
	{
		std::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		foo.swap(bar);

		there << "foo contains:\n";
		for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			there << it->first << " => " << it->second << '\n';

		there << "bar contains:\n";
		for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			there << it->first << " => " << it->second << '\n';
}
{
		ft::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		foo.swap(bar);

		mine << "foo contains:\n";
		for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			mine << it->first << " => " << it->second << '\n';

		mine << "bar contains:\n";
		for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			mine << it->first << " => " << it->second << '\n';
}
/*UPPER_BOUND*/
{
	std::map<char,int> mymap;
	std::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		there << it->first << " => " << it->second << '\n';
	}
	{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
 		mine << it->first << " => " << it->second << '\n';
	}
	/*VALUE_COMP*/
	{
		std::map<char,int> mymap;
		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;

		there << "mymap contains:\n";

		std::pair<char,int> highest = *mymap.rbegin();          // last element
		std::map<char,int>::iterator it = mymap.begin();
		do {
			there << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
	}
	
	{
		ft::map<char,int> mymap;
		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;

		mine << "mymap contains:\n";

		ft::pair<char,int> highest = *mymap.rbegin();          // last element
		ft::map<char,int>::iterator it = mymap.begin();
		do {
			mine << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
	}
	/*Relational operators*/
	{
		std::map<char,int> foo,bar;
		foo['a']=100;
		foo['b']=200;
		bar['a']=10;
		bar['z']=1000;

		// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
		if (foo==bar) there << "foo and bar are equal\n";
		if (foo!=bar) there << "foo and bar are not equal\n";
		if (foo< bar) there << "foo is less than bar\n";
		if (foo> bar) there << "foo is greater than bar\n";
		if (foo<=bar) there << "foo is less than or equal to bar\n";
		if (foo>=bar) there << "foo is greater than or equal to bar\n";
	}
	{
		ft::map<char,int> foo,bar;
		foo['a']=100;
		foo['b']=200;
		bar['a']=10;
		bar['z']=1000;

		// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
		if (foo==bar) mine << "foo and bar are equal\n";
		if (foo!=bar) mine << "foo and bar are not equal\n";
		if (foo< bar) mine << "foo is less than bar\n";
		if (foo> bar) mine << "foo is greater than bar\n";
		if (foo<=bar) mine << "foo is less than or equal to bar\n";
		if (foo>=bar) mine << "foo is greater than or equal to bar\n";
	}
	/*SWAP*/
	{
		std::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		swap(foo,bar);

		there << "foo contains:\n";
		for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			there << it->first << " => " << it->second << '\n';

		there << "bar contains:\n";
		for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			there << it->first << " => " << it->second << '\n';
	}
	{
		ft::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		swap(foo,bar);

		mine << "foo contains:\n";
		for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			mine << it->first << " => " << it->second << '\n';

		mine << "bar contains:\n";
		for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			mine << it->first << " => " << it->second << '\n';
	}

}

