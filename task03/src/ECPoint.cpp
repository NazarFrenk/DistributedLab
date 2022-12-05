#include "ECPoint.h"

ECPoint::ECPoint()
{
    X = 1;
    Y = 1;
}

ECPoint::ECPoint(long long x, long long y)
{
    this->X = x;
    this->Y = y;
}

long long find_module(long long number, long long mod)
{
    if (number > 0)
    {
        return (number % mod);
    }
    else
    {
        return (number + (abs(number / mod) + 1) * mod);
    }
}

bool ECPoint::IsOnCurveCheck(ECPoint a)
{
    long long check = a.X * a.X * a.X + a.a * a.X + a.b;
    // cout << a.Y * a.Y << " " << check << " " << check % a.p << endl;
    if (check > 0)
    {
        return (((a.Y * a.Y) % a.p) == check % a.p);
    }
    else
    {
        return (((a.Y * a.Y) % a.p) == check + (abs(check / a.p) + 1) * a.p);
    }
}
ECPoint ECPoint::AddECPoints(ECPoint a, ECPoint b)
{
    ECPoint c = *new ECPoint();

    long long m = (b.Y - a.Y) / (b.X - a.X);
    m = find_module(m, a.p);

    c.X = m * m - a.X - b.X;
    c.X = find_module(c.X, a.p);

    c.Y = m * (c.X - a.X) + a.Y;
    c.Y = find_module(c.Y, a.p);

    return c;
}
ECPoint ECPoint::DoubleECPoints(ECPoint a)
{
    ECPoint c = *new ECPoint();

    long long h = (3 * a.X * a.X + a.a) / (2 * a.Y);
    h = find_module(h, a.p);

    c.X = h * h - 2 * a.X;
    c.X = find_module(c.X, a.p);

    c.Y = h * (a.X - c.X) - a.Y;
    c.Y = find_module(c.Y, a.p);

    return c;
}
ECPoint ECPoint::ScalarMult(ECPoint a, long long k)
{
    ECPoint c = *new ECPoint();

    if (k > 2)
    {
        c = DoubleECPoints(a);
        
        for (size_t i = 0; i < k - 2; i++)
        {
            c = AddECPoints(c, a);
        }
    }
    else if (k == 2)
    {
        c = DoubleECPoints(a);
    }
    else
    {
        return a;
    }

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