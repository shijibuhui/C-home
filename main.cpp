#include <iostream>
#include "person.hpp"

int main()
{
    //测试使用///////////////////
    User user1("姓名","he123456",15144749397);
    std::cout << user1.getAccount() << std::endl;
    std::cout << user1.getName() << std::endl;
    std::cout << user1.getPassword() << std::endl;
    ///////////////////////////////
    return 0;
}