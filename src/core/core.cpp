#include "core.hpp"
#include <iostream>


core::core() {
    std::cout << "core constructor called" << std::endl;
}

core::~core() {
    std::cout << "core destructor called" << std::endl;
}