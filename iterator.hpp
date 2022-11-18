
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
	class kiterator {
		public:
			typedef typename 	iterator_traits<T>::iterator_category		iterator_category;
			typedef typename	iterator_traits<T>::value_type				value_type;
			typedef typename	iterator_traits<T>::difference_type			difference_type;
			typedef	typename	iterator_traits<T>::pointer				pointer;
			typedef	typename	iterator_traits<T>::reference		reference;

			kiterator(): ptr_iter(nullptr){}
			kiterator(pointer u):ptr_iter(u){}
			kiterator(const kiterator &oth): ptr_iter(oth.ptr_iter){}
			~kiterator() {}
			reference operator*() const{return *ptr_iter;}
			kiterator operator- (difference_type n) const{return (ptr_iter - n);}
			kiterator& operator++() { return ++(*this);}
			kiterator  operator++(int) { kiterator tmp = *this; ++(*this); return tmp;}
			kiterator& operator--(){return (--(*this));}
			kiterator& operator-= (difference_type n) {return (ptr_iter -= n);}
			kiterator& operator+= (difference_type n) {return (ptr_iter += n);}
			kiterator  operator--(int) { kiterator tmp = *this; --(*this); return tmp;}
			reference operator[] (difference_type n) const {return *(ptr_iter - n);}
			kiterator operator+ (difference_type n) const {return (ptr_iter + n);}

		private:
			pointer	ptr_iter;
	};
}
#endif