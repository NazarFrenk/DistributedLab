#include "ECPoint.h"

ECPoint::ECPoint()
{
}

ECPoint::ECPoint(long int x, long int y)
{

}

bool ECPoint::IsOnCurveCheck(ECPoint a)
{
    return false;
}
ECPoint ECPoint::AddECPoints(ECPoint a, ECPoint b)
{
    ECPoint c = *new ECPoint();

    return c;
}
ECPoint ECPoint::DoubleECPoints(ECPoint a)
{
    return a;
}
ECPoint ECPoint::ScalarMult(ECPoint a, long int k)
{
    ECPoint c = *new ECPoint();

    return c;
}
std::string ECPoint::ECPointToString(ECPoint point)
{
    return FBLU("Here will be point");
}
void ECPoint::PrintECPoint(ECPoint point)
{
    cout << ECPointToString(point) << endl;
}

ECPoint::~ECPoint()
{
}