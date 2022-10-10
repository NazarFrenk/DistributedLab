#include <iostream>
#include "my_functions.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int m, a;

    cout << "Enter m: ";
    cin >> m;
    cout << "Enter a: ";
    cin >> a;

    cout << "m is: " << m << endl;
    cout << "a is: " << a << endl;

    find_module(a, m);

    return 0;
}