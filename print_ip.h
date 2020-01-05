#pragma once
#include <string>
#include <iostream>


template< typename T,
    typename = std::enable_if_t< std::is_integral< T >::value > >
void
print_ip( const T& val )
{
    auto temp = static_cast<typename std::make_unsigned<T>::type>(val);

    for( int i = sizeof(T)-1; i >= 0; --i)
    {
        std::cout << ( ( temp >> (i*8)) & 0xFFu );

        if( i != 0 )
            std::cout  << ".";
    }
}

template< typename T >
auto
print_ip( const T& val ) -> decltype( (void)( val.begin() ), void() )
{
    for (auto element = val.cbegin(); element != val.cend(); ++element)
    {
        if (element != val.cbegin())
        {
            std::cout  << ".";
        }

        std::cout  << *element;
    }
}

void
print_ip( const std::string& val )
{
    std::cout << val;
}







