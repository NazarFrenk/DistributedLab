#include "ECPoint.h"

ECPoint::ECPoint()
{
    X = 1;
    Y = 1;
}

ECPoint::ECPoint(long long x, long long y)
{
    X = x;
    Y = Y;
}

bool ECPoint::IsOnCurveCheck(ECPoint a)
{
    return (a.Y * a.Y == a.X * a.X * a.X + a.a * a.X + a.b);
}
ECPoint ECPoint::AddECPoints(ECPoint a, ECPoint b)
{
    ECPoint c = *new ECPoint();

    long long m = (a.Y - b.Y) / (a.X - b.X);

    c.X = m * m - a.X - b.X;
    c.Y = a.Y + m * (c.X - a.X);

    return c;
}
ECPoint ECPoint::DoubleECPoints(ECPoint a)
{
    ECPoint c = *new ECPoint();

    return c;
}
ECPoint ECPoint::ScalarMult(ECPoint a, long long k)
{
    ECPoint c = *new ECPoint();

    return c;
}
std::ostream &operator<<(std::ostream &os, const ECPoint &point)
{
    os << "Point (X, Y): (" << point.X << ", " << point.Y << ")";
    return os;
}
std::string ECPoint::ECPointToString(ECPoint point)
{
    std::stringstream ss;
    ss << point;

    return ss.str();
}
void ECPoint::PrintECPoint(ECPoint point)
{
    cout << ECPointToString(point) << endl;
}

ECPoint::~ECPoint()
{
}