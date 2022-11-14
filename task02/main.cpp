#include <iostream>
#include "ECPoint.h"
#include "colors.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    ECPoint *point1 = new ECPoint();
    ECPoint *point2 = new ECPoint(25, 50);

    ECPoint point3 = ECPoint::AddECPoints(*point1, *point2);
    ECPoint::IsOnCurveCheck(point3);
    ECPoint::DoubleECPoints(point3);
    ECPoint::ScalarMult(point3, 5);
    ECPoint::PrintECPoint(point3);

    return 0;
}