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

int ModularArithmetic::prime_number()
{
    vector<int> result;
    bool is_prime = true;

    int A = 1, B = 100000;
    int random;

    bool prime[B + 1];
    std::memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= B; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= B; i += p)
            {
                prime[i] = false;
            }
        }
    }

    // Add all prime numbers to result vector
    for (int p = 2; p <= B; p++)
    {
        if (prime[p])
        {
            result.push_back(p);
        }
    }

    if (!result.empty())
    {
        bool find = false;
    
        while (!find)
        {
            random = rand() % result.size() - 1;
            if (!(result[random] <= A))
            {
                find = true;
            }
        }
        cout << FGRN("Random prime number between 1 and 100000 is ") << result[random] << endl;
    }

    return result[random];
}

ModularArithmetic::~ModularArithmetic()
{
}