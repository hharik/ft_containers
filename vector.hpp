
#ifndef vector_HPP
# define vector_HPP

#include <type_traits>
#include <iostream>
#include <iterator>
#include <vector>
#include <iostream>
#include "iterator.hpp"
#include "struct_utils.hpp"

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


		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) 
		: ptr(NULL) , _size(0), _capacity(0),  allc(alloc)
		{
			assign(first, last);
		}

		explicit vector(const allocator_type& alloc = allocator_type()): ptr(NULL), _size(0), _capacity(0), allc(alloc) {}
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

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : ptr(NULL), _size(0), _capacity(0), allc(alloc)
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
				size_type old_size = _size;
				if (_size > 0){
					for (size_type i = 0; i < _size; i++)
						allc.construct(tmp + i, *(ptr + i));
				}
				// for (size_type i = 0; i < _size; i++)
				// 	allc.destroy(ptr + i);
				clear();
				if (ptr && _capacity)
					allc.deallocate(ptr, _capacity);
				ptr = tmp;
				_capacity = n;
				_size = old_size;
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
	
		const_iterator begin() const{return const_iterator(ptr);} 
		const_iterator end() const { return const_iterator(ptr + _size);}
		iterator begin() {return iterator(ptr);}
		iterator end() { return iterator((ptr + _size));}
		reverse_iterator rbegin() { return (reverse_iterator(ptr + _size));}
		reverse_iterator rend(){return reverse_iterator(ptr);}
		const_reverse_iterator rbegin() const { return reverse_iterator(ptr + _size);}
		const_reverse_iterator rend() const{return reverse_iterator(ptr);}
		// SFINAE Substitution Failure is not an Error
		template <class InputIterator> void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			size_type index = position - begin();
			vector tmp;
			tmp.assign(first, last);
			size_type n  = tmp.size();
		
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
				allc.construct((ptr + i - 1 + n), *(ptr + i - 1));
				allc.destroy(ptr + i - 1);
			}
			
			for (size_type i = 0; i < n ;i++){
				allc.construct((ptr + (index) + i), tmp[i]);
			}
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
				else
					reserve(2 * _capacity);
				if (_size + n > _capacity)
					reserve(_size + n);
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
		//    difference_type pos  = position -  begin();
                
        //         if(_capacity == _size)
        //         {
        //             if(!_capacity)
        //                 reserve(1);
        //             else 
        //                 reserve(_capacity * 2);
        //         }

        //         for(difference_type i = _size; i > pos; i--)
        //         {
        //             allc.construct(ptr + i, *(ptr + (i - 1)));
        //             allc.destroy(ptr + (i - 1));
        //         }
        //         allc.construct(ptr + pos, val);
        //         _size++;
        //         return(ptr + pos);	 
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
			size_type pos = position - begin();
			vector a(begin(),position);
			vector b(position + 1, end());
			*this = a;
			insert(end(), b.begin(), b.end());
			return (ptr + pos);
		}
		iterator erase (iterator first, iterator last)
		{
			size_type index = first - begin(); 
			vector tmp(begin() , first);
			vector tmp2(last, end());
			*this = tmp;
			insert(end(), tmp2.begin(), tmp2.end());
			return (ptr + index);
		}
		void resize (size_type n, value_type val = value_type())
		{
			
			if (n > _size)
			{
				if (n > _capacity)
					reserve(2 * _capacity);
				if (n > _size)
					reserve(n);
				for (size_type i = 0; i < (_size - n); i++)
					push_back(val);
				_size = n;
				
			}
			if (n < _size)
			{
				for (size_type i = n; i < _size; i++)
					allc.destroy(ptr + i);
				_size = n;
			}

		}

		template <class InputIterator> void assign(InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			typename ft::iterator_traits<InputIterator>::iterator_category test;
			allocate_for(first, last, test);
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
			swapU(this->ptr, v.ptr);
			swapU(this->_size, v._size);
			swapU(this->_capacity, v._capacity);
			swapU(this->allc, v.allc);
		}

		void pop_back()
		{
			if (_size > 0)
				allc.destroy(ptr + --_size);
		}
		void push_back(const value_type& val)
		{
			if (_size  == _capacity)
			{
				if (_size > 0)
					reserve(_capacity * 2);
				else
					reserve(1);
			}
			allc.construct((ptr + _size++), val);
		}
		~vector()
		{
			clear();
			if (ptr)
			{
				allc.deallocate(ptr, _capacity);
				_capacity = 0;
				_size = 0;
				this->ptr = NULL;
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
			if (_size > 0) return false; return true;
		}
		size_type capacity() const { return _capacity; }
		size_type	size() const { return _size;}
		size_type	max_size() const { 
			if (PTRDIFF_MAX < allc.max_size())
				return PTRDIFF_MAX;
			return allc.max_size();
			}

		template <class t, class alloc> friend bool operator== (const vector<t,alloc>& lhs, const vector<t,alloc>& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			return (ft::equal(rhs.begin(), rhs.end(), lhs.begin()));
		}
		template <class t, class alloc> friend bool operator!= (const vector<t,alloc>& lhs, const vector<t,alloc>& rhs) { return !(lhs == rhs);}
		template <class t, class alloc> friend bool operator< (const vector<t,alloc>& lhs, const vector<t,alloc>& rhs) {
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}
		template <class t, class alloc> friend bool operator<= (const vector<t,alloc>& lhs, const vector<t,alloc>& rhs) { 
			if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) || lhs == rhs)
				return true;
			return false;
		}
		template <class t, class alloc> friend bool operator> (const vector<t,alloc>& lhs, const vector<t,alloc>& rhs) { 
			return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end())); // checking the opposite 
		}
		template <class t, class alloc> friend bool operator>= (const vector<t,alloc>& lhs, const vector<t,alloc>& rhs) { 
			if (lhs > rhs || lhs == rhs)
				return true;
			return false;
		}



		private:
		pointer	ptr;
		size_type	_size;
		size_type    _capacity;
		allocator_type	allc;

		template <typename U>void	swapU(U &o_ptr, U &other)
		{
			U tmp = o_ptr;
			o_ptr = other;
			other = tmp;
		}

		template<class iter>
		void	allocate_for(iter first, iter last, std::forward_iterator_tag)
		{
			//forward_iterator_tag
			vector tmp;
			while (first != last)
			{
				tmp.push_back(*first);
				first++;
			}
			reserve(tmp.size());
			clear();
			for (size_type i = 0; i < tmp.size(); i++)
				push_back(tmp[i]);
		}

		template<class iter>
		void	allocate_for(iter first, iter last, std::input_iterator_tag)
		{
			//input_iterator_tag
			clear();
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
	};
	template <class T, class Alloc> void swap(vector<T,Alloc>& x, vector<T,Alloc>& y) {x.swap(y);}
}

   // difference_type pos  = position -  begin();
                
                // if(_capacity == _size)
                // {
                //     if(!_capacity)
                //         reserve(1);
                //     else 
                //         reserve(_capacity * 2);
                // }

                // for(difference_type i = _size; i > pos; i--)
                // {
                //     allc.construct(ptr + i, *(ptr + (i - 1)));
                //     allc.destroy(ptr + (i - 1));
                // }
                // allc.construct(ptr + pos, val);
                // _size++;
                // return(ptr + pos);

#endif