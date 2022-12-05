#include <iostream>
#include "ECPoint.h"
#include "BigInt.h"
#include "colors.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    /*
    cout << BOLD(FYEL("BigInt tests")) << endl;
    BigInt first("12345");
    cout << FBLU("The number of digits in first big integer = ") << Length(first) << endl;
    BigInt second(12345);
    if (first == second)
    {
        cout << FGRN("First and second are equal!") << endl;
    }
    else
    {
        cout << FRED("Not equal!") << endl;
    }
    BigInt third("10000");
    BigInt fourth("100000");
    if (third < fourth)
    {
        cout << FBLU("Third is smaller than fourth!") << endl;
    }
    BigInt fifth("10000000");
    if (fifth > fourth)
    {
        cout << FBLU("Fifth is larger than fourth!") << endl;
    }

    // Printing all the numbers
    cout << FBLU("First = ") << first << endl;
    cout << FBLU("Second = ") << second << endl;
    cout << FBLU("Third = ") << third << endl;
    cout << FBLU("Fourth = ") << fourth << endl;
    cout << FBLU("Fifth = ") << fifth << endl;

    // Incrementing the value of first
    first++;
    cout << FGRN("After incrementing the value of first is : ") << first << endl;
    BigInt sum;
    sum = fourth + fifth;
    cout << FGRN("Sum of fourth and fifth = ") << sum << endl;
    BigInt product;
    product = second * third;
    cout << FGRN("Product of second and third = ") << product << endl;

    // Print the fibonaccii number from 1 to 100

    cout << BOLD(FYEL("-------------------------Fibonacci------------------------------")) << endl;
    for (int i = 0; i <= 100; i++)
    {
        BigInt Fib;
        Fib = BigInt::NthFibonacci(i);
        cout << FBLU("Fibonacci ") << i << FBLU(" = ") << Fib << endl;
    }
    cout << BOLD(FYEL("-------------------------Catalan------------------------------")) << endl;
    for (int i = 0; i <= 100; i++)
    {
        BigInt Cat;
        Cat = BigInt::NthCatalan(i);
        cout << FBLU("Catalan ") << i << FBLU(" = ") << Cat << endl;
    }

    // Calculating factorial of from 1 to 100
    cout << BOLD(FYEL("-------------------------Factorial------------------------------")) << endl;
    for (int i = 0; i <= 100; i++)
    {
        BigInt fact;
        fact = BigInt::Factorial(i);
        cout << FBLU("Factorial of ") << i << FBLU(" = ") << fact << endl;
    }
    */
    cout << BOLD(FYEL("Generate default ECPoint")) << endl;
    ECPoint *point1 = new ECPoint();
    ECPoint::PrintECPoint(*point1);

    cout << BOLD(FYEL("ECPoint creation with pre-defined")) << endl;
    ECPoint *point2 = new ECPoint(4, 3);
    ECPoint::PrintECPoint(*point2);

    cout << BOLD(FYEL("Add 2 ECPoints")) << endl;
    ECPoint point3 = ECPoint::AddECPoints(*point1, *point2);
    ECPoint::PrintECPoint(point3);

    cout << BOLD(FYEL("Check if ECPoint is on curve")) << endl;
    if (ECPoint::IsOnCurveCheck(point3))
    {
        cout << BOLD(FGRN("Point is on curve")) << endl;
    }
    else
    {
        cout << FRED("Point isn't on curve") << endl;
    }

    cout << BOLD(FYEL("Doudle ECPoint")) << endl;
    ECPoint::DoubleECPoints(point3);
    ECPoint::PrintECPoint(point3);

    cout << BOLD(FYEL("Scalar ECPoint")) << endl;
    ECPoint::ScalarMult(point3, 5);
    ECPoint::PrintECPoint(point3);

    return 0;
}