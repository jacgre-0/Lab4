#include "Owner.h"

Owner::Owner(std::string name, std::string address, bool allowedToDrive)
    :
    name(name),
    address(address),
    allowedToDrive(allowedToDrive)
{}

void Owner::Print() const {
    std::cout << "Name: " << name << '\n'
        << "Address: " << address << '\n'
        << "Is allowed to drive: " << std::boolalpha << allowedToDrive << std::endl;
}