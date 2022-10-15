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
    cout << FYEL("4 - solve a*x = b mod m") << endl;
    cout << FYEL("5 - find prime number between A and B") << endl;
    cout << FYEL("6 - exit") << endl;
    cout << endl;
}

void ModularArithmetic::set_number()
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
        set_number();
    }
    if (a >= 0)
    {
        cout << FGRN("a mod m is ") << a % m << endl;
    }
    else
    {
        if ((a % m) != 0)
        {
            cout << FGRN("a mod m is ") << a + (abs(a / m) + 1) * m << endl;
        }
        else
        {
            cout << FGRN("a mod m is 0") << endl;
        }
    }
}

void ModularArithmetic::find_pow_module()
{
    int a, b, d = 1, t;

    cout << FYEL("Enter a: ");
    cin >> a;
    cout << FYEL("Enter b: ");
    cin >> b;

    if (m == 0)
    {
        set_number();
    }
    
        // convert b to binary
        std::string binary = std::bitset<8>(b).to_string();

        t = a;
        bool init = false;

        int len = binary.length();
        while (len--)
        {
            if (binary[len] == '1')
            {
                if (!init)
                {
                    d = a % m;
                    init = true;
                }
                else
                {
                    d = (d * t) % m;
                }
            }
            t = (t * t) % m;
        }
        cout << FGRN("Answer is: ") << d << endl;
}

void ModularArithmetic::linear_equation()
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