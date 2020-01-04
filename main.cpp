#include "print_ip.h"
#include <string>
#include <vector>
#include <list>


using namespace std::string_literals;

int
main()
{
    std::vector<int> v = {7, 5, 16, 8};
    std::list<int> l = {255, 255, 255, 255};

    print_ip(char(-1));
    std::cout << std::endl;

    print_ip(short(0));
    std::cout << std::endl;

    print_ip(int(2130706433));
    std::cout << std::endl;

    print_ip(8875824491850138409LL);
    std::cout << std::endl;

    print_ip("1.1.1.1"s);
    std::cout << std::endl;

    print_ip(v);
    std::cout << std::endl;

    print_ip(l);
    std::cout << std::endl;

    return 0;
}