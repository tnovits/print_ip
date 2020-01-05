#define BOOST_TEST_MODULE ip_pool_test_module

#include "print_ip.h"
#include <boost/test/unit_test.hpp>
#include <string>

using namespace std::string_literals;

BOOST_AUTO_TEST_SUITE( print_ip_test_suite )

BOOST_AUTO_TEST_CASE( print_ip_char_test )
{
    std::stringstream sstream;
    auto backupCoutBuffer = std::cout.rdbuf();

    std::cout.rdbuf( sstream.rdbuf() );
    print_ip(char(-1));
    std::cout.rdbuf( backupCoutBuffer );
    BOOST_CHECK(  sstream.str() == "255"s);
}

BOOST_AUTO_TEST_CASE( print_ip_short_test )
{
    std::stringstream sstream;
    auto backupCoutBuffer = std::cout.rdbuf();

    std::cout.rdbuf( sstream.rdbuf() );
    print_ip(short(0));
    std::cout.rdbuf( backupCoutBuffer );

    BOOST_CHECK(  sstream.str() == "0.0"s);
}

BOOST_AUTO_TEST_CASE( print_ip_int_test )
{
    std::stringstream sstream;
    auto backupCoutBuffer = std::cout.rdbuf();

    std::cout.rdbuf( sstream.rdbuf() );
    print_ip(int(2130706433));
    std::cout.rdbuf( backupCoutBuffer );

    BOOST_CHECK(  sstream.str() == "127.0.0.1"s);
}

BOOST_AUTO_TEST_CASE( print_ip_long_test )
{
    std::stringstream sstream;
    auto backupCoutBuffer = std::cout.rdbuf();

    std::cout.rdbuf( sstream.rdbuf() );
    print_ip(8875824491850138409LL);
    std::cout.rdbuf( backupCoutBuffer );

    BOOST_CHECK(  sstream.str() == "123.45.67.89.101.112.131.41"s);
}

BOOST_AUTO_TEST_CASE( print_ip_string_test )
{
    std::stringstream sstream;
    auto backupCoutBuffer = std::cout.rdbuf();

    std::cout.rdbuf( sstream.rdbuf() );
    print_ip("1.1.1.1"s);
    std::cout.rdbuf( backupCoutBuffer );

    BOOST_CHECK(  sstream.str() == "1.1.1.1"s);
}

BOOST_AUTO_TEST_CASE( print_ip_v_test )
{
    std::vector<int> v = {7, 5, 16, 8};

    std::stringstream sstream;
    auto backupCoutBuffer = std::cout.rdbuf();

    std::cout.rdbuf( sstream.rdbuf() );
    print_ip(v);
    std::cout.rdbuf( backupCoutBuffer );

    BOOST_CHECK(  sstream.str() == "7.5.16.8"s);
}

BOOST_AUTO_TEST_CASE( print_ip_l_test )
{
    std::list<int> l = {255, 255, 255, 255};

    std::stringstream sstream;
    auto backupCoutBuffer = std::cout.rdbuf();

    std::cout.rdbuf( sstream.rdbuf() );
    print_ip(l);
    std::cout.rdbuf( backupCoutBuffer );

    BOOST_CHECK(  sstream.str() == "255.255.255.255"s);
}

BOOST_AUTO_TEST_SUITE_END()