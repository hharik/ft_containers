#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iterator>
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
		typedef const T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};
	template<class T>
	class iterator {
		public:
			typedef typename 	iterator_traits<T*>::iterator_category		iterator_category;
			typedef typename	iterator_traits<T*>::value_type				value_type;
			typedef typename	iterator_traits<T*>::difference_type		difference_type;
			typedef	typename	iterator_traits<T*>::pointer				pointer;
			typedef	typename	iterator_traits<T*>::reference				reference;


			iterator(): ptr_iter(NULL){}
			iterator(pointer u):ptr_iter(u){}
			pointer base()const {return ptr_iter;}
			iterator(const iterator &oth): ptr_iter(oth.ptr_iter){}
			template<typename U> iterator(const iterator<U> &y) {ptr_iter = y.base();} // type U
			~iterator() {}
			reference operator*() const{return *ptr_iter;}
			iterator operator- (difference_type n) const{return (ptr_iter - n);}
			iterator& operator++() { ++(ptr_iter); return *this; }
			iterator  operator++(int) { iterator tmp = *this; ++(ptr_iter); return tmp;}
			iterator& operator--(){--(ptr_iter); return *this;}
			iterator& operator-= (difference_type n) {(ptr_iter -= n); return *this;}
			iterator& operator+= (difference_type n) {(ptr_iter += n); return *this;}
			iterator  operator--(int) { iterator tmp = *this; --(ptr_iter); return tmp;}
			reference operator[] (difference_type n) const {return *(ptr_iter + n);}
			iterator operator+ (difference_type n) const {return (ptr_iter + n);}
			pointer operator->() const { return &(operator*());}

			//relational operators
			friend iterator operator+ (difference_type n, const iterator<T>& rev_it) { return (rev_it + n);};
			friend difference_type operator-(const iterator<T>& lhs, const iterator<T>& rhs) { return (lhs.base() - rhs.base());}
			template <class Iter1, class Iter2> friend bool operator== (const Iter1& lhs, const Iter2& rhs){return (lhs.base() == rhs.base());}
			template <class Iter1, class Iter2> friend bool operator!= (const Iter1& lhs, const Iter2& rhs){return !(lhs.base() == rhs.base());}
			template <class Iter1, class Iter2> friend bool operator<  (const Iter1& lhs, const Iter2& rhs) { return lhs.base() < rhs.base();}
			template <class Iter1, class Iter2> friend bool operator> (const Iter1& lhs, const Iter2& rhs) { return lhs.base() > rhs.base();}
			template <class Iter1, class Iter2> friend bool operator>= (const Iter1& lhs, const Iter2& rhs) { return !(lhs.base() < rhs.base());}
			template <class Iter1, class Iter2> friend bool operator<= (const Iter1& lhs, const Iter2& rhs) { return !(lhs.base() > rhs.base());}

		private:
			pointer	ptr_iter;
	};

	template <class Iterator>
	class reverse_iterator {
			public:
			    typedef Iterator                                            	iterator_type;
				typedef typename ft::iterator_traits<Iterator>::iterator_category	 iterator_category;
				typedef typename ft::iterator_traits<Iterator>::value_type			 value_type;
				typedef typename ft::iterator_traits<Iterator>::difference_type		 difference_type;
				typedef typename ft::iterator_traits<Iterator>::pointer				 pointer;
				typedef typename ft::iterator_traits<Iterator>::reference			 reference;
			
				reverse_iterator(): current() {}
				explicit reverse_iterator (iterator_type it) : current(it) {}
				reverse_iterator (const reverse_iterator<Iterator>& rev_it) : current(rev_it.current) {}
				template<typename U> reverse_iterator (const reverse_iterator<U>& rev_it) {current = rev_it.base();}
				iterator_type base() const {return current;}
				reverse_iterator operator- (difference_type n) const {return reverse_iterator(current + n);}
				reverse_iterator& operator--() {++current; return *this;}
				reverse_iterator  operator--(int) {reverse_iterator tmp = *this; ++(current); return tmp;}
				reverse_iterator& operator-= (difference_type n) { (current += n); return *this;}
				reference operator[] (difference_type n) const {return current.operator[](-n - 1);}
				reference operator*() const { 
					Iterator tmp = current;
					--tmp;
					return *tmp;
				}  // - 1
				reverse_iterator operator+ (difference_type n) const {return reverse_iterator(current - n);}
				reverse_iterator& operator++() { --current; return (*this);}
				reverse_iterator  operator++(int){reverse_iterator tmp = *this; --(current); return tmp;}
				reverse_iterator& operator+= (difference_type n) {(current -= n); return *this;}
				pointer operator ->() const { return &(operator *());}
				//non-member overloads
		friend difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return (rhs.base() - lhs.base());}
		friend reverse_iterator<Iterator> operator+ (difference_type n, const reverse_iterator<Iterator>& rev_it) { return reverse_iterator(rev_it + n);}
	
			template <class Iter1, class Iter2>  friend bool operator== (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) { return (lhs.base() == rhs.base());}
			template <class Iter1, class Iter2>  friend bool operator!= (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) { return (lhs.base() != rhs.base());}
			template <class Iter1, class Iter2>  friend bool operator<  (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) { return (lhs.base() > rhs.base());}
			template <class Iter1, class Iter2>  friend bool operator<= (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) { return (lhs.base() >= rhs.base());}
			template <class Iter1, class Iter2>  friend bool operator>  (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) { return (lhs.base() < rhs.base());}	
			template <class Iter1, class Iter2>  friend bool operator >= (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) { return (lhs.base() <= rhs.base());}

		private:
		    Iterator current;
	};

}
#endif