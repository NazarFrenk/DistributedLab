#ifndef ECPOINT_H
#define ECPOINT_H

#include <iostream>
#include <vector>
#include "colors.h"

using std::cin;
using std::cout;
using std::endl;

class ECPoint
{
private:
    long int X, Y;
    static std::string ECPointToString(ECPoint point); // Convert point to string
public:
    ECPoint();                                        // G-generator receiving
    ECPoint(long int x, long int y);                  // ECPoint creation with pre-defined parameters
    static bool IsOnCurveCheck(ECPoint a);            // P ∈ CURVE?
    static ECPoint AddECPoints(ECPoint a, ECPoint b); // P + Q
    static ECPoint DoubleECPoints(ECPoint a);         // 2P
    static ECPoint ScalarMult(ECPoint a, long int k); // k * P
    static void PrintECPoint(ECPoint point);          // Print point
    ~ECPoint();
};

#endif