#ifndef MAP_HPP_
#define MAP_HPP_

#include "pair.hpp"
#include "avl.hpp"
#include <iostream>
#include "struct_utils.hpp"
#include "bidirectional_iterator.hpp"
#include <map>
#include <functional>

namespace ft {
	template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<ft::pair<const Key, T> > >
class map
{
	private:
		typedef typename ft::AVL<Key, T, Compare, Allocator>* 				_node_pointer;
		typedef typename ft::TreeNode<Key, T>* 				tree_pointer;
	public:
 		// types:
		class value_compare;
		typedef Key                                      key_type;
		typedef T                                        mapped_type;
		typedef ft::pair<const key_type, mapped_type>    value_type;
		typedef Compare                                  key_compare;
		typedef Allocator                                allocator_type;
		typedef typename allocator_type::reference       reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer         pointer;
		typedef typename allocator_type::const_pointer   const_pointer;
		typedef typename allocator_type::size_type       size_type;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename ft::AVL<key_type, mapped_type, key_compare, allocator_type>			 Tree_type;

		typedef ft::bidirectional_iterator<value_type, ft::TreeNode<Key, T> >                  iterator;
		typedef ft::bidirectional_iterator<const value_type, const ft::TreeNode<Key, T> >      const_iterator;
   		typedef ft::bidirectional_reverse_iterator<iterator>          reverse_iterator;
    	typedef ft::bidirectional_reverse_iterator<const_iterator>    const_reverse_iterator;

	value_compare value_comp() const { return value_compare(key_compare());}
	
	explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	: size_(0), alloc_pair_(alloc),key_map(),mapped_map() ,tree_(),comp_key(comp){ }
	template <class InputIterator>  map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	: size_(0), alloc_pair_(alloc), key_map(), mapped_map(),  tree_(),comp_key(comp)  {
		insert(first, last);
	}
	~map() {
		//avl is clearing the tree
	}
	map (const map& x) {
		*this = x;
	}
	map & operator = ( const map& x ) {
		if (!empty())
			clear(); 
		// key_map = x.key_map;
		alloc_pair_ = x.alloc_pair_;
		mapped_map = x.mapped_map;
		comp_key = x.comp_key;
		// size_ = x.size_;
		if (x.size())
			insert(x.begin(), x.end());
		return *this;
	}

	//begin && end iterators 
	iterator begin(){
		return iterator(tree_.begin(), tree_.end());
	}
	iterator end() { 
		return iterator(NULL, tree_.end()); 
	}
	const_iterator begin() const { return iterator(tree_.begin(), tree_.end());}
	const_iterator end() const { return iterator(NULL, tree_.end());}
	//REVERSE ITERATOR

	reverse_iterator rbegin() { return reverse_iterator(end());}

	reverse_iterator rend() { return reverse_iterator(begin());}

	const_reverse_iterator rbegin() const{ return const_reverse_iterator(end()); }

	const_reverse_iterator rend() const{ return const_reverse_iterator(const_iterator(begin())); }
	
	//INSERT

	ft::pair<iterator,bool> insert (const value_type& val) {
		tree_pointer tmp = tree_.search(val.first);
		if (tmp != NULL)
			return ft::make_pair(iterator(tmp), false);
		tree_.insert(val);
		size_++;
		return ft::make_pair(iterator(tree_.search(val.first)), true);
	}

	iterator insert (iterator position, const value_type& val)
	{
		(void) position;
		tree_.insert(val);
		size_++;
		return iterator(tree_.search(val.first), tree_.end());
	}
	template <class InputIterator>  void insert (InputIterator first, InputIterator last) {
		while (first != last)
		{
			tree_.insert(*first);
			first++;
		}
		size_ = tree_.size_;
	}

	size_type count (const key_type& k) const
	{
		if (tree_.search(k) == NULL)
			return 0;
		return 1;
	}
	mapped_type& operator[] (const key_type& k){
		return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
	}
	void	print() { tree_.print();}

	void clear() {
		tree_.destory_avl();
		size_ = 0;
	}
	size_type size() const { return tree_.size_; }
	//ERASE 
	size_type erase (const key_type& k) { 
		if (find(k) != end())
		{
			size_--;
			tree_.delete_p(k);
			return 1;
		}
		return 0;
	}
	void erase (iterator position) {
		tree_.delete_p(position->first);
		size_ = tree_.size_;
	}
	void erase (iterator first, iterator last) 
	{
		ft::vector<key_type> tmp;
		while (first != last)
		{
			tmp.push_back(first->first);
			first++;
		}
		for (size_t i = 0; i < tmp.size(); i++)
		{
			tree_.delete_p(tmp[i]);
		}
		size_ = tree_.size_;
	}
	//FIND
	iterator find (const key_type& k){
		tree_pointer tmp = tree_.search(k);
		if (tmp == NULL) return end();
		return iterator(tmp);
	}
	const_iterator find (const key_type& k) const {
		tree_pointer tmp = tree_.search(k);
		if (tmp == NULL) return end();
		return const_iterator(tmp);
	}

	//UPPER BOUND 
	iterator upper_bound (const key_type& k){ 
		tree_pointer tmp = tree_.upper_bound(k);
		if (tmp == NULL) return end();
		return iterator(tmp);
	}

	const_iterator upper_bound (const key_type& k) const { 
		tree_pointer tmp = tree_.upper_bound(k);
		if (tmp == NULL)	return end();
		return const_iterator(tmp);
	}
	// LOWER BOUND
	
	iterator lower_bound (const key_type& k) { 
		tree_pointer tmp = tree_.lower_bound(k);
		if (tmp == NULL) return end();
		return iterator(tmp);
	}
	const_iterator lower_bound (const key_type& k) const { 
		tree_pointer tmp = tree_.lower_bound(k);
		if (tmp == NULL) return end();
		return const_iterator(tmp);
	}
	// EQUaL_RANGE
	pair<iterator,iterator> equal_range (const key_type& k) {
		return ft::make_pair(lower_bound(k), upper_bound(k));
	}
	pair<const_iterator,const_iterator> equal_range (const key_type& k) const { 
		return ft::make_pair(lower_bound(k), upper_bound(k));
	}
	//GETERS
	allocator_type get_allocator() const { return alloc_pair_;}
	size_type max_size() const {
		return alloc_pair_.max_size();
	}
	bool empty() const { if (size_ == 0) return true; return false;}
	key_compare key_comp() const { return key_compare();}
	// value_compare value_comp() const { return  }

	void swap (map& x) {
		size_t i = x.tree_.size_;
		x.tree_.size_ = tree_.size_;
		tree_.size_ = i;

		tree_pointer tmp = x.tree_.root;
		x.tree_.root = tree_.root;
		tree_.root = tmp;
		// tree_.swap(x.tree_.root);
		// Tree_type tmp = x.tree_;
		// x.tree_ = tree_;
		// tree_ = tmp;
		// // map tmp = x;
		// // x = *this;
		// // *this = tmp;
	}
	private:
		size_t				size_;
		allocator_type		alloc_pair_;
		tree_pointer		_tree;
		key_type			key_map;
		mapped_type			mapped_map;
		Tree_type	tree_;
		key_compare		comp_key;

	};
	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y) { x.swap(y);}

	template <class _Key, class _T, class _Compare, class _Alloc>
	class map<_Key,_T,_Compare,_Alloc>::value_compare : public std::binary_function<value_type,value_type,bool>
	{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
	friend class map<_Key, _T, _Compare, _Alloc>;
	protected:
	_Compare comp;
	value_compare (_Compare c) : comp(c) {}  // constructed with map's comparison object
	public:
	typedef bool result_type;
	typedef value_type first_argument_type;
	typedef value_type second_argument_type;
	bool operator() (const value_type& x, const value_type& y) const
	{
		return comp(x.first, y.first);
	}
	};

	template <class Key, class T, class Compare, class Alloc>  //The equality comparison (operator==) is performed by first comparing sizes,
	// and if they match, the elements are compared sequentially using operator==, stopping at the first mismatch (as if using algorithm equal).
		bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
			if ( lhs.size() != rhs.size())
				return false;
			return (ft::equal(rhs.begin(),rhs.end(), lhs.begin()));
		}
	
	template <class Key, class T, class Compare, class Alloc> 
		bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) { return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());}
	
	template <class Key, class T, class Compare, class Alloc>  
		bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) { return !(lhs == rhs);}
	
	template <class Key, class T, class Compare, class Alloc>  
		bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {return (rhs < lhs); }
	
	template <class Key, class T, class Compare, class Alloc> 
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {return !(rhs < lhs);}

	template <class Key, class T, class Compare, class Alloc> 
		bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,  const map<Key,T,Compare,Alloc>& rhs ) { return !(lhs < rhs);}

};


#endif