#ifndef STRUCT_UTILS_HPP_

#define STRUCT_UTILS_HPP_

namespace ft{

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


}
#endif