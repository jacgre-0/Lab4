#pragma once
#include <string>
#include <iostream>

class Owner {
public:
    Owner(std::string name, std::string address, bool allowedToDrive);
    void Print() const;
private:
    std::string name;
    std::string address;
    bool allowedToDrive;
};
