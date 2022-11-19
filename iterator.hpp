
#ifndef ITERATOR_HPP
#define ITERATOR_HPP
namespace ft
{
	template<class T>
	struct iterator_traits
	{
		typedef typename T::difference_type difference_type;
		typedef typename T::value_type value_type;
		typedef typename T::pointer pointer;
		typedef typename T::reference reference;
		typedef typename T::iterator_category iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template<class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};
	template<class T>
	class iterator {
		public:
			typedef typename 	iterator_traits<T>::iterator_category		iterator_category;
			typedef typename	iterator_traits<T>::value_type				value_type;
			typedef typename	iterator_traits<T>::difference_type			difference_type;
			typedef	typename	iterator_traits<T>::pointer				pointer;
			typedef	typename	iterator_traits<T>::reference		reference;

			iterator(): ptr_iter(nullptr){}
			iterator(pointer u):ptr_iter(u){}
			iterator(const iterator &oth): ptr_iter(oth.ptr_iter){}
			~iterator() {}
			reference operator*() const{return *ptr_iter;}
			iterator operator- (difference_type n) const{return (ptr_iter - n);}
			iterator& operator++() { return ++(*this);}
			iterator  operator++(int) { iterator tmp = *this; ++(*this); return tmp;}
			iterator& operator--(){return (--(*this));}
			iterator& operator-= (difference_type n) {return (ptr_iter -= n);}
			iterator& operator+= (difference_type n) {return (ptr_iter += n);}
			iterator  operator--(int) { iterator tmp = *this; --(*this); return tmp;}
			reference operator[] (difference_type n) const {return *(ptr_iter - n);}
			iterator operator+ (difference_type n) const {return (ptr_iter + n);}
			//relational operators
			friend bool operator== (const iterator<T>& lhs, const iterator<T>& rhs){return (lhs.ptr_iter == rhs.ptr_iter);}
			friend bool operator!= (const iterator<T>& lhs, const iterator<T>& rhs){return !(lhs.ptr_iter == rhs.ptr_iter);}
			friend bool operator<  (const iterator<T>& lhs, const iterator<T>& rhs) { return lhs.ptr_iter < rhs.ptr_iter;}
			friend bool operator> (const iterator<T>& lhs, const iterator<T>& rhs) { return lhs.ptr_iter > rhs.ptr_iter;}
			friend bool operator>= (const iterator<T>& lhs, const iterator<T>& rhs) { return !(lhs.ptr_iter > rhs.ptr_iter);}
			friend bool operator<= (const iterator<T>& lhs, const iterator<T>& rhs) { return !(lhs.ptr_iter < rhs.ptr_iter);}

		private:
			pointer	ptr_iter;
	};
}

#endif