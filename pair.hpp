#ifndef PAIR_HPP_
#define PAIR_HPP_
#include <iostream>
namespace ft {
//Note that the type is declared as struct instead of class so that all members are public. Thus,
//for any value pair, direct access to the individual values is possible.
	template <class T1, class T2> 
	struct pair {
		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

/* default constructor
* - T1 () and T2 () force initialization for built-in types */
// initializes the values of pair by using int() and float() for example, which yields 0 in both cases 
		pair() : first(T1()), second(T2()) {}
		pair (const first_type& a, const second_type& b) : first(a), second(b) { }
		template<class U, class V> pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {
		}

		//operator
		pair& operator= (const pair& pr) {
			this->first = pr.first;
			this->second = pr.second;
			return *this;
		}
	};
	template <class T1, class T2>
	pair<T1,T2> make_pair ( T1 x, T2 y)
	{
		return ( pair<T1,T2>(x,y) );
	}
	
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }
};


#endif 