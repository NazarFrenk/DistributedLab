#ifndef MODULAR_ARITHMETIC_H
#define MODULAR_ARITHMETIC_H

#include <iostream>
#include <vector>
#include "colors.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class ModularArithmetic
{
private:
    int m = 0;
public:
    ModularArithmetic();
    void print_menu();
    void set_m();
    void find_module();
    void simple_number();
    ~ModularArithmetic();
};

#endif