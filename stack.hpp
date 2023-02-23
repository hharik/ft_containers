#ifndef STACK_HPP_
#define STACK_HPP_
#include "vector.hpp"
#include <stack>

namespace ft{

	template <class T, class Container = ft::vector<T> >
	class stack
	{

	public:
		typedef Container                                container_type;
		typedef typename container_type::value_type      value_type;
		typedef typename container_type::reference       reference;
		typedef typename container_type::const_reference const_reference;
		typedef typename container_type::size_type       size_type;

		explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}
		// stack( const stack& other ) { *this = other;}		// stack& operator=( const stack& other ) { c = other.c; return *this;}

		//Element access
		reference top(){ return c.back();}
		const_reference top() const { return c.back();}
		//Capacity
		bool empty() const { return (c.empty());}
		size_type size() const { return c.size(); }
		//Modifiers
		void pop() { c.pop_back();}
		void push (const value_type& val) { c.push_back(val);}
		template <class y, class Container1> friend bool operator== (const stack<y,Container1>& lhs, const stack<y,Container1>& rhs) { return (lhs.c == rhs.c);}
		template <class y ,class Container1> friend bool operator!= (const stack<y,Container1>& lhs, const stack<y,Container1>& rhs) {return (lhs.c != rhs.c);}
		template <class y, class Container1> friend bool operator<  (const stack<y,Container1>& lhs, const stack<y,Container1>& rhs) { return  (lhs.c < rhs.c);}
		template <class y, class Container1> friend bool operator<= (const stack<y,Container1>& lhs, const stack<y,Container1>& rhs) { return (lhs.c <= rhs.c);}
		template <class y, class Container1> friend bool operator>  (const stack<y,Container1>& lhs, const stack<y,Container1>& rhs) {return (lhs.c > rhs.c);}
		template <class y, class Container1> friend bool operator>= (const stack<y,Container1>& lhs, const stack<y,Container1>& rhs) { return (lhs.c >= rhs.c);}
	protected:
		container_type c;
	};
};

#endif