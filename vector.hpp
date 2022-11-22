
#ifndef VECTOR_HPP
# define VECTOR_HPP


#include <iterator>
#include <vector>
#include <iostream>
#include "iterator.hpp"

namespace ft
{
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

		vector(): _size(0), _capacity(0),ptr(nullptr) {}
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
		vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : allc(alloc)
		{
			ptr = allc.allocate(n);
			for (size_type i = 0; i < n; i++)
				allc.construct(ptr + i, val);
			_size = n;
			_capacity = n;
		}
		vector	&operator = (const vector& v)
		{
			if (_size > 0){
				for (size_type i = 0; i < _size; i++)
					allc.destroy(ptr + i);
				allc.deallocate(ptr, _capacity);
			}
			_size = v._size;
			_capacity = v._capacity;
			ptr = allc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				allc.construct(ptr + i, *(v.ptr + i));
			return *this;
		}
		void print()
		{
			for (size_type i = 0; i < _size; i++)
				std::cout <<"vale < > " << " "  << *(ptr + i) << std::endl;
		}
		void	reserve(size_type n)
		{
			if (n > max_size())
				throw std::length_error("Error reserve");
			if (n > _capacity)
			{
				pointer tmp = allc.allocate(n);
				if (_size > 0){
					for (size_type i = 0; i < _size; i++)
						allc.construct(tmp + i, *(ptr + i));
				}
				for (size_type i = 0; i < _size; i++)
					allc.destroy(ptr + i);
				allc.deallocate(ptr,_capacity);
				ptr = tmp;
				_capacity = n;
			}
		}
		reference front(){return *(ptr);}

		//reverse && iterator begin() && end()
	
		iterator begin() {return iterator(ptr);}
		iterator end() { return iterator((ptr  + _size));}
		const_iterator begin() const{return const_iterator(ptr);} //still working on const 
		const_iterator end() const { return const_iterator(ptr + _size);}
		reverse_iterator rbegin() { return (reverse_iterator(ptr + _size));}
		reverse_iterator rend(){return reverse_iterator(ptr);}
		const_reverse_iterator rbegin() const { return reverse_iterator(ptr + _size);}
		const_reverse_iterator rend() const{return reverse_iterator(ptr);}
		template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last)
		{
			int i = 0;
			InputIterator p = first;
			while (p != last && i <= (last - first))
			{
				std::cout << *(p) << std::endl;
				insert(position, *(p));
				i++;
				p++;
			}
			// size_type j = 0;
			// size_type i = last - first;
			// while (first != last && j < i){
			// 	insert(position + j, first);
			// 	first++;
			// 	j++;

			// }
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			int i = 0;
			while (i < n)
			{
				insert(position + i, val);
				i++;
			}
		}
		iterator insert (iterator position, const value_type& val)
		{
			size_type index = position  - begin();
			if (_size + 1 > _capacity)
			{
				if (_capacity == 0)
					reserve(2 * _capacity + 1);
				else if (_capacity > 0)
					reserve(2 * _capacity);
			}
			allc.construct(ptr + _size, val);
			_size++;
			int i = _size - 1;
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
			return (iterator(ptr));
		}
		iterator erase (iterator position)
		{
			size_type index = position  - begin();
			// std::cout << index << std::endl;
			pointer tmp = allc.allocate(_capacity);
			int i = 0;
			int j =  0;
			while (i < _size)
			{
				if (i != index)
				{
					allc.construct(tmp + j, *(ptr + i));
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
			_size--;
			ptr = tmp;
			return (iterator(ptr));
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
				for (size_type i = 0; i < (_size - n); i++)
					push_back(val);
				_size = n;
				return ;
			}
			if (n < _size)
			{
				for (size_type i = n; i < _size; i++)
					allc.destroy(ptr + i);
				_size = n;
				return ;
			}

		}
		void assign(iterator first, iterator last)
		{
			
			clear();
			size_type n = last - first;
			if (n > max_size())
				throw std::length_error("Error max size");
			std::cout << "  ++++++++ ++ + ++ + + . "  <<  n << std::endl;
			if (n > _capacity)
			{
				reserve (n);
				_size = n;
				_capacity = n;
				size_type i = 0;
				while (first != last)
				{
					allc.construct((ptr + i), *first);
					i++;
					first++;
				}
				return ;
			}
			else{
				
				size_type i = 0;
				while (first != last)
				{
					// std::cout << "urmom !! " << i << std::endl;
					allc.construct((ptr + i), *first);
					i++;
					first++;
				}
				// print();
				_size = n;
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
		reference operator[] (size_type n) { return *(ptr + n);}
		reference at (size_type n){
			if (n >= _size)
				throw std::out_of_range("Out of Range error");
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
			if (_size > 0)
			{
				for (size_type i = 0; i < size(); i++)
					allc.destroy(ptr + i);
				allc.deallocate(ptr, _capacity);
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