#include <iostream>
#include "ECPoint.h"
#include "colors.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << BOLD(FYEL("Generate default ECPoint")) << endl;
    ECPoint *point1 = new ECPoint();
    ECPoint::PrintECPoint(*point1);

    cout << BOLD(FYEL("ECPoint creation with pre-defined")) << endl;
    ECPoint *point2 = new ECPoint(25, 50);
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