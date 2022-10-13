#include <iostream>
#include "ModularArithmetic.h"
#include "colors.h"

using std::cin;
using std::cout;
using std::endl;

int get_input();

int main()
{
    int m, a, b, choice;
    bool isRun = true;

    ModularArithmetic *arith = new ModularArithmetic();

    while (isRun)
    {
        arith->print_menu();
        choice = get_input();
        switch (choice)
        {
        case 1:
            arith->set_m();
            break;
        case 2:
            arith->find_module();
            break;
        case 5:
            arith->prime_number();
            break;
        case 6:
            isRun = false;

        default:
            continue;
            break;
        }
    }

    return 0;
}

int get_input()
{
    int choice;
    cin >> choice;

    return choice;
}