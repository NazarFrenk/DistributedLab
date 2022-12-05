#ifndef ECPOINT_H
#define ECPOINT_H

#include <iostream>
#include <vector>
#include <sstream>
#include "colors.h"

using std::cin;
using std::cout;
using std::endl;

class ECPoint
{
private:
    long long a = 3, b = 2;
    long long X, Y;
    static std::string ECPointToString(ECPoint point); // Convert point to string
    friend std::ostream& operator<<(std::ostream& os, const ECPoint& point);
public:
    ECPoint();                                         // G-generator receiving (y^2 = x^3 + ax + b)
    ECPoint(long long x, long long y);                 // ECPoint creation with pre-defined parameters
    static bool IsOnCurveCheck(ECPoint a);             // P ∈ CURVE?
    static ECPoint AddECPoints(ECPoint a, ECPoint b);  // P + Q
    static ECPoint DoubleECPoints(ECPoint a);          // 2P
    static ECPoint ScalarMult(ECPoint a, long long k); // k * P
    static void PrintECPoint(ECPoint point);           // Print point
    ~ECPoint();
};

#endif