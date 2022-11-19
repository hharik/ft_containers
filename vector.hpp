
#ifndef VECTOR_HPP_
# define VECTOR_HPP_


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
		// typedef implementation-defined                   const_iterator;
		typedef typename allocator_type::size_type       size_type;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::pointer         pointer;
		typedef typename allocator_type::const_pointer   const_pointer;
		typedef iterator<pointer>							iterator;
		// typedef std::reverse_iterator<iterator>          reverse_iterator;
		// typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

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
			if (_size > 0){
				for (size_type i = 0; i < _size; i++)
					allc.construct(ptr + i, *(v.ptr + i));
			}
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
			if (n >_capacity)
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
		//iterator begin() && end()
		iterator begin() {return iterator(ptr);}
		iterator end() { return iterator((ptr  + _size));}
		iterator insert (iterator position, const value_type& val)
		{
			size_type index = position  - begin();
			if (_size + 1 > _capacity)
			{
				reserve(2 * _capacity + 1);

			}
			else
			{
				allc.construct(ptr + _size, val);
				_size++;
				iterator new_val = end() - 1;
				iterator prev_val = end() - 2;
				while (new_val != position)
				{
					*(new_val) = *(prev_val);
					new_val--;
					prev_val--;
				}
				*new_val = val;
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
		void assign (size_type n, const value_type& val)
		{
			clear();
			if (n > max_size())
				throw std::length_error("Error resize");
			if (n > _capacity)
			{
				reserve(n);
				for (size_type i = 0; i < n; i++){
					ptr = allc.construct((ptr + i), val);
				}
				_size = n;
				_capacity = n;
				return ;
			}
			for (size_type i = 0; i < n; i++)
				ptr = allc.construct((ptr + i), val);
			_size = n;
		}
		allocator_type get_allocator() const { return allc;}
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
				reserve(2 * _capacity + 1);
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
			std::cout << "destructored" << std::endl;
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
		private:
		pointer	ptr;
		size_type	_size;
		size_type    _capacity;
		allocator_type	allc;
	};
}
#endif