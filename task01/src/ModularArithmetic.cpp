#include "ModularArithmetic.h"

ModularArithmetic::ModularArithmetic()
{
}

void ModularArithmetic::print_menu()
{
    cout << endl;
    cout << FYEL("Switch:") << endl;
    cout << FYEL("1 - enter module m") << endl;
    cout << FYEL("2 - solve a mod m = x") << endl;
    cout << FYEL("3 - solve a^b mod m = x") << endl;
    cout << FYEL("5 - find prime number between A and B") << endl;
    cout << FYEL("6 - exit") << endl;
    cout << endl;
}

void ModularArithmetic::set_m()
{
    int module;
    do
    {
        cout << FYEL("Enter m: ");
        cin >> m;
        if (m <= 0)
        {
            cout << FYEL("m must be > 0") << endl;
        }

    } while (m <= 0);
}

void ModularArithmetic::find_module()
{
    int a;

    cout << FYEL("Enter a: ");
    cin >> a;

    if (m == 0)
    {
        set_m();
    }

    cout << FGRN("a mod m is ") << a % m << endl;
}

void ModularArithmetic::find_pow_module()
{
}

void ModularArithmetic::prime_number()
{
    vector<int> result;
    bool is_prime = true;

    int A, B;

    cout << FYEL("Enter A: ");
    cin >> A;
    cout << FYEL("Enter B: ");
    cin >> B;

    while (A < B)
    {
        is_prime = true;

        // 0 and 1 are not prime numbers
        if (A == 0 || B == 1)
        {
            is_prime = false;
        }

        for (int i = 2; i <= A / 2; ++i)
        {
            if (A % i == 0)
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
        {
            result.push_back(A);
        }

        ++A;
    }

    if (!result.empty())
    {
        int random = rand() % result.size();
        cout << FGRN("Random prime number between A and B is ") << result[random] << endl;
    }
    else
    {
        cout << FRED("There is no prime number between A and B") << endl;
    }
}

ModularArithmetic::~ModularArithmetic()
{
}