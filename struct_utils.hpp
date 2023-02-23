#ifndef STRUCT_UTILS_HPP_

#define STRUCT_UTILS_HPP_

namespace ft{

// SFINAE Substitution Failure is not an Error 
// this is the overloaded function method
template<bool Cond, class T = void> struct enable_if {};
template<class T> struct enable_if<true, T> { typedef T type; };

/********* IS_INTEGRAL *********/

template<typename T, typename v = void>
struct is_integral{
	static const bool value = false;
};

template<typename T>
struct is_integral <int, T>
{
	static const bool value = true;
};

template<typename T>
struct is_integral <char, T>
{
	static const bool value = true;
};

template<typename T>
struct is_integral <bool, T>
{
	static const bool value = true;
};

template<typename T>
struct is_integral <signed char, T>
{
	static const bool value = true;
};

template<typename T>
struct is_integral <unsigned char, T>
{
	static const bool value = true;
};


template<typename T>
struct is_integral <wchar_t, T>
{
	static const bool value = true;
};

template<typename T>
struct is_integral <short, T>
{
	static const bool value = true;
};

template<typename T>
struct is_integral <long, T>
{
	static const bool value = true;
};

template<typename T>
struct is_integral <long long, T>
{
	static const bool value = true;
};

template<typename T>
struct is_integral <unsigned short, T>
{
	static const bool value = true;
};

template<typename T>
struct is_integral <unsigned int, T>
{
	static const bool value = true;
};

template<typename T>
struct is_integral <unsigned long, T>
{
	static const bool value = true;
};

template<typename T>
struct is_integral <unsigned long long, T>
{
	static const bool value = true;
};

/************************ EQUAL *************************************/
template <class InputIterator1, class InputIterator2>
  bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
  while (first1!=last1) {
    if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
      return false;
    ++first1; ++first2;
  }
  return true;
}
template <class InputIterator1, class InputIterator2, class BinaryPredicate> 
 bool equal (InputIterator1 first1, InputIterator1 last1,InputIterator2 first2, BinaryPredicate pred) {
 while (first1!=last1) {
    if (!pred(*first1,*first2)) 
      return false;
    ++first1; ++first2;
  }
  return true;
}

/********************lexicographical_compare ****************************/
//func check less
template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                               InputIterator2 first2, InputIterator2 last2)
{
	while (first1!=last1)
	{
		if (first2==last2 || *first2<*first1) return false;
		else if (*first1<*first2) return true;
		++first1; ++first2;
	}
	return (first2!=last2);
}
}
#endif