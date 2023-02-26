#ifndef  BIDIRECTIONAL_ITERATOR_HPP_
#define BIDIRECTIONAL_ITERATOR_HPP_

#include "map.hpp"

namespace ft{
	//T is pair && T1 is TreeNode
	template <class T, class T1>
	class bidirectional_iterator{
		typedef	T1*	node_type;
		public:
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::bidirectional_iterator_tag iterator_category;
		bidirectional_iterator() : _curr(), _end() {}
		bidirectional_iterator(node_type node_beg, node_type node_end) : _curr(node_beg), _end(node_end){ } 
		bidirectional_iterator(const bidirectional_iterator &oth) { 
			*this = oth;
		}
		template <typename P, typename R>	bidirectional_iterator(const bidirectional_iterator<P, R> &ot) {
			this->_curr = ot.base_curr();
			this->_end = ot.base_end();
		}
		bidirectional_iterator &operator=(const bidirectional_iterator &other) 
		{
			_curr = other._curr;
			_end = other._end;
			return *this;
		}

		bidirectional_iterator(node_type node) {
			_curr = node;
			_end = max_node(node);
		}
		node_type	max_node(node_type node) { 
			while (node && node->right)
				node = node->right;
			return node;
		}
		node_type	min_node(node_type node) { 
			while (node && node->left)
				node = node->left;
			return node;
		}

		node_type	increment_node(node_type node)
		{
			if (node == _end)
			{
				return NULL;
			}
			if (node && node->right != NULL)
			{
				return min_node(node->right);
			}
			else if (node){
			node_type parent = node->parent;
			while (parent && node == parent->right)
			{
				node = parent;
				parent = parent->parent;
			}
			node = parent;
			}
			return node;
		}
		node_type descrement_node(node_type node) {
			if (node && node->left != NULL)
				return max_node(node->left);
			else if (node)
			{
				node_type parent = node->parent;
				while (parent && node == parent->left)
				{
					node = parent;
					parent = parent->parent;
				}
				node = parent;
			}
			return node;
		}
		bidirectional_iterator operator++(void) {
			_curr = increment_node(_curr);
			return *this;
		}
		
		bidirectional_iterator operator++(int) {
			node_type node = _curr;
			_curr = increment_node(_curr);
			return node;
		}
		bidirectional_iterator& operator--(){
			if (_curr == NULL)
				_curr = _end;
			else 
				_curr = descrement_node(_curr);
			return *this;
		}
	
		bidirectional_iterator  operator--(int){
			node_type	node = _curr;
			//needs to check if the _curr == NULL and assign the end to it after because it will access something that doesn't exist
			if (_curr == NULL)
			{
				_curr = _end;
				node = _end;
			}
			else 
				_curr = descrement_node(_curr);
			return node;	
		}
		
		reference operator*() const { return *(_curr->data);}
		
		pointer operator->() const {
 		 return &(operator*());
		}

		node_type base_curr() const  { return _curr;}
		node_type base_end() const {return _end;}
		template<class T_, class P_> bool operator== (const bidirectional_iterator<T_, P_> &lhs) const { return (base_curr() == lhs.base_curr());}
		template<class T_, class P_> bool operator!= (const bidirectional_iterator<T_, P_> &lhs) const { return !(base_curr() == lhs.base_curr());}

		private:
			node_type	_curr;
			node_type	_end;
	
	};template <class Iterator>
	class bidirectional_reverse_iterator {
			public:
			    typedef Iterator                                            	iterator_type;
				typedef typename ft::iterator_traits<Iterator>::iterator_category	 iterator_category;
				typedef typename ft::iterator_traits<Iterator>::value_type			 value_type;
				typedef typename ft::iterator_traits<Iterator>::difference_type		 difference_type;
				typedef typename ft::iterator_traits<Iterator>::pointer				 pointer;
				typedef typename ft::iterator_traits<Iterator>::reference			 reference;
			
				bidirectional_reverse_iterator(): current() {}
				explicit bidirectional_reverse_iterator (iterator_type it) : current(it) {}
				bidirectional_reverse_iterator (const bidirectional_reverse_iterator<Iterator>& rev_it) : current(rev_it.current) {} 
				template<typename U> bidirectional_reverse_iterator (const bidirectional_reverse_iterator<U>& rev_it) {current = rev_it.base();} // conversion constructor
				iterator_type base() const {return current;}

				bidirectional_reverse_iterator& operator--() {++current; return *this;}
				bidirectional_reverse_iterator  operator--(int) {bidirectional_reverse_iterator tmp = *this; ++(current); return tmp;}
			
				reference operator*() const { 
					Iterator tmp = current;
					--tmp;
					return *tmp;
				}  // - 1
				bidirectional_reverse_iterator& operator++() { --current; return (*this);}
				bidirectional_reverse_iterator  operator++(int){bidirectional_reverse_iterator tmp = *this; --(current); return tmp;}
	
				pointer operator ->() const { return &(operator *());}
				//non-member overloads
		friend difference_type operator- (const bidirectional_reverse_iterator<Iterator>& lhs, const bidirectional_reverse_iterator<Iterator>& rhs) {return (rhs.base() - lhs.base());}
		friend bidirectional_reverse_iterator<Iterator> operator+ (difference_type n, const bidirectional_reverse_iterator<Iterator>& rev_it) { return bidirectional_reverse_iterator(rev_it + n);}
	
			template <class Iter1, class Iter2>  friend bool operator== (const bidirectional_reverse_iterator<Iter1>& lhs, const bidirectional_reverse_iterator<Iter2>& rhs) { return (lhs.base() == rhs.base());}
			template <class Iter1, class Iter2>  friend bool operator!= (const bidirectional_reverse_iterator<Iter1>& lhs, const bidirectional_reverse_iterator<Iter2>& rhs) { return (lhs.base() != rhs.base());}

		private:
		    Iterator current;
	};
	//T is map Iterator
};


#endif