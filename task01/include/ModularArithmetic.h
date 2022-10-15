#ifndef MODULAR_ARITHMETIC_H
#define MODULAR_ARITHMETIC_H

#include <iostream>
#include <vector>
#include <bitset>
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
    void set_number();
    void find_module();
    void find_pow_module();
    void linear_equation();
    void prime_number();
    ~ModularArithmetic();
};

#endif