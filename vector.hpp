
#ifndef vector_HPP
# define vector_HPP

#include <type_traits>
#include <iostream>
#include <iterator>
#include <vector>
#include <iostream>
#include "iterator.hpp"

namespace ft
{
	//still need to implement is_integral

	template<bool Cond, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };

	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
		typedef T                                        value_type;
		typedef Allocator                                allocator_type;
		typedef typename allocator_type::reference       reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef iterator<const value_type>				 const_iterator;
		typedef iterator<value_type>					 iterator;
		typedef typename allocator_type::size_type       size_type;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::pointer         pointer;
		typedef typename allocator_type::const_pointer   const_pointer;
		typedef reverse_iterator<const_iterator>     const_reverse_iterator;
		typedef reverse_iterator<iterator>  reverse_iterator;


		template <class InputIterator> vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if< !std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr) : ptr(nullptr) , _size(0), _capacity(0),  allc(alloc)
		{
			assign(first, last);
		}

		explicit vector(const allocator_type& alloc = allocator_type()): ptr(nullptr), _size(0), _capacity(0), allc(alloc) {}
		vector(const vector& other) 
		{
			_size = other._size;
            _capacity = other._capacity;
			ptr = allc.allocate(_capacity);
			if (_size > 0)
			{	
				for (size_type i = 0; i < _size; i++){
					allc.construct(ptr + i, *(other.ptr + i));
				}
			}
		}
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : ptr(nullptr), _size(0), _capacity(0), allc(alloc)
		{
			if (n > 0)
			{
				ptr = allc.allocate(n);
				for (size_type i = 0; i < n; i++)
					allc.construct(ptr + i, val);
				_size = n;
				_capacity = n;
			}
		}
		vector	&operator = (const vector& v)
		{
			assign(v.begin(), v.end());
			return *this;
		}
	
		void	reserve(size_type n)
		{
			if (n > max_size())
				throw std::length_error("vector");
			if (n > _capacity)
			{
				pointer tmp = allc.allocate(n);
				if (_size > 0){
					for (size_type i = 0; i < _size; i++)
						allc.construct(tmp + i, *(ptr + i));
				}
				for (size_type i = 0; i < _size; i++)
					allc.destroy(ptr + i);
				if (_capacity)
					allc.deallocate(ptr, _capacity);
				ptr = tmp;
				_capacity = n;
			}
		}
		reference front(){return *(ptr);}
		const_reference front() const {return *(ptr);}

		//returns 
	    reference at (size_type n){
			if (n >= _size || n < 0)
				throw std::out_of_range("vector");
			return (ptr[n]);
		}
		const_reference at (size_type n) const{
			if (n >= _size || n < 0)
				throw std::out_of_range("vector");
			return (ptr[n]);
		}
		reference back(){return *(ptr + (_size - 1));}
		const_reference back() const{return *(ptr + (_size - 1));}
		//reverse && iterator begin() && end()
	
		iterator begin() {return iterator(ptr);}
		iterator end() { return iterator((ptr  + _size));}
		const_iterator begin() const{return const_iterator(ptr);} //still working on const 
		const_iterator end() const { return const_iterator(ptr + _size);}
		reverse_iterator rbegin() { return (reverse_iterator(ptr + _size));}
		reverse_iterator rend(){return reverse_iterator(ptr);}
		const_reverse_iterator rbegin() const { return reverse_iterator(ptr + _size);}
		const_reverse_iterator rend() const{return reverse_iterator(ptr);}

		template <class InputIterator> void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if< !std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
		{
			size_type index = position - begin();
			vector tmp;
			tmp.assign(first, last);
			size_type n  = tmp.size();
			// std::cout << n << std::endl;
			if (_size + tmp.size() > _capacity)
			{
				if (_capacity == 0)
					reserve(tmp.size());
				else if (_size + tmp.size() < (2 * _capacity))
					reserve(2 * _capacity);
				else if (_size + tmp.size() > (2 * _capacity))
					reserve(_size + tmp.size());
			}
			for (size_type i = _size; i > index; i--)
			{			
				allc.construct((ptr + i + n - 1), *(ptr + i - 1));
				// allc.destroy(ptr + i);
			}
			for (size_type i = index; i < tmp.size() ;i++, first++)
				*(ptr + i) = *first;
			_size += n;
		}
		void insert (iterator position, size_type n, const value_type& val)
		{
			if (n > max_size())
				throw std::length_error("vector");
			size_type index = position  - begin();
			if (_size + n > _capacity)
			{
				if (_capacity == 0)
					reserve(n);
				// else if (_size + n > (2 * _capacity))
				// 	reserve(n);
				else
					reserve(2 * _capacity);
			}
			for (size_type j = 0 ; j < n; j++)
			{
				allc.construct(ptr + _size, val);
				_size++;
				size_type i = _size - 1;
				iterator new_val = end() - 1;
				iterator prev_val = end() - 2;
				while (new_val != position)
				{
					if (i == index)
						break ;
					*new_val = *prev_val;
					new_val--;
					prev_val--;
					i--;
				}
				*new_val = val;
				index++;
			}
		}
		iterator insert (iterator position, const value_type& val)
		{
			size_type index = position  - begin();
			// if (position > _size)
			// 	return ;
			if (_size + 1 > _capacity)
			{
				if (_capacity == 0)
					reserve(2 * _capacity + 1);
				else if (_capacity > 0)
					reserve(2 * _capacity);
			}
			allc.construct(ptr + _size, val);
			_size++;
			size_type i = _size - 1;

			iterator new_val = end() - 1;
			iterator prev_val = end() - 2;
			while (new_val != position)
			{
				if (i == index)
					break ;
				*(new_val) = *(prev_val);
				new_val--;
				prev_val--;
				i--;
			}
			*new_val = val;
			return (iterator(new_val));
		}

		iterator erase (iterator position)
		{
			size_type j = 0;
			size_type index = position - begin();
			std::cout << index << std::endl;
			pointer tmp = allc.allocate(_capacity);
			size_type i = 0;
			while (i < _size)
			{
				if (i != index)
				{
					allc.construct((tmp + j), *(ptr + i));
					j++;
				}
				i++;
			}
			i = 0;
			while (i < _size)
			{
				allc.destroy(ptr + i);
				i++;
			}
			// allc.deallocate(ptr, _capacity);
			// ptr = allc.allocate(_capacity);
			_size--;
			ptr = tmp;
			return (begin() - 1);
		}
		iterator erase (iterator first, iterator last)
		{
			while (first != last)
			{
				erase(first);
				first++;
			}
			return (iterator(ptr));
		}
		void resize (size_type n, value_type val = value_type())
		{
			
			if (n > _size)
			{	
				reserve(n);
				for (size_type i = 0; i < (_size - n); i++)
					push_back(val);
				_size = n;
				
			}
			else
			{
				for (size_type i = n; i < _size; i++)
					allc.destroy(ptr + i);
				_size = n;
			}

		}
		template <class InputIterator> void assign(InputIterator first, InputIterator last)
		{
			vector a;
			for (;first != last; first++)
				a.push_back(*first);
			size_type n = a.size();
			if (n > max_size())
				throw std::length_error("vector");
			clear();
			if (n > _capacity)
				reserve(a._capacity);
			
			for (size_type i = 0; i < n; i++)
			{
				allc.construct(ptr + i, a[i]);
				_size++;
			}
		}

		void assign (size_type n, const value_type& val)
		{
			clear();
			if (n > max_size())
				throw std::length_error("Error resize");
			if (n > _capacity)
			{
				reserve(n);
				for (size_type i = 0; i < n; i++){
					allc.construct((ptr + i), val); // i did assign int to ptr but shit went crazy check later
				}
				_size = n;
				_capacity = n;
				return ;
			}
			for (size_type i = 0; i < n; i++)
				allc.construct((ptr + i), val); // i did assign int to ptr but shit went crazy check later
			_size = n;
		}
		allocator_type get_allocator() const { return allc;}
		reference operator[] (size_type n) {
			if (n >= _size || n < 0)
				throw std::out_of_range("vector");
			return (ptr[n]);
		}
		const_reference operator[] (size_type n) const {
			if (n >= _size || n < 0)
				throw std::out_of_range("vector");
			return (ptr[n]);
		}

		void swap(vector &v)
		{
			vector tmp = v;
			v = *this;
			*this = tmp;
		}
		void pop_back()
		{
			if (_size > 0)
				allc.destroy(ptr + _size--);
		}
		void push_back(const value_type& val)
		{
			if (_size  == _capacity)
			{
				if (_capacity == 0)
					reserve(2 * _capacity + 1);
				else if (_capacity > 0)
					reserve(2 * _capacity);
			}
			allc.construct((ptr + _size++), val);
		}
		~vector()
		{
			
			for (size_type i = 0; i < size(); i++)
				allc.destroy(ptr + i);
			if (_capacity)
			{
				allc.deallocate(ptr, _capacity);
				_capacity = 0;
			}
		}
		void clear()
		{
			if (_size > 0)
			{
				for (size_type i = 0; i < _size; i++)
					allc.destroy(ptr + i);
				_size = 0;		
			}
		}
		bool empty() const
		{
			if (_size > 0)
				return false;
			return true;
		}
		size_type capacity() const { return _capacity; }
		size_type	size() const { return _size;}
		size_type	max_size() const { return allc.max_size();}

		//Relational operators non mumber functions (aka friend func's)
		friend bool operator== (const vector<T>& lhs, const vector<T>& rhs) { return (lhs.ptr == rhs.ptr);}
		friend bool operator!= (const vector<T>& lhs, const vector<T>& rhs) {return !(lhs.ptr == rhs.ptr);}
		friend bool operator<  (const vector<T>& lhs, const vector<T>& rhs) {return (lhs.ptr < rhs.ptr);}
		friend bool operator<=  (const vector<T>& lhs,const vector<T>& rhs) { return !(lhs.ptr < rhs.ptr);}
		friend bool operator>  (const vector<T>& lhs, const vector<T>& rhs) { return (lhs.ptr > rhs.ptr);}
		friend bool operator>= (const vector<T>& lhs, const vector<T>& rhs) { return !(lhs.ptr > rhs.ptr);}
		private:
		pointer	ptr;
		size_type	_size;
		size_type    _capacity;
		allocator_type	allc;
	};
}
#endif