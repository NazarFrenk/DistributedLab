#include <iostream>
#include "ECPoint.h"
#include "ModularArithmetic.h"
#include "colors.h"

int main()
{
    ModularArithmetic *arith = new ModularArithmetic();

    long long da = arith->prime_number();
    long long db = arith->prime_number(); 

    ECPoint *pointG = new ECPoint(2, 4);

    ECPoint pointHa = ECPoint::ScalarMult(*pointG, da);
    ECPoint pointHb = ECPoint::ScalarMult(*pointG, db);

    ECPoint pointS1 = ECPoint::ScalarMult(pointHb, da);
    ECPoint pointS2 = ECPoint::ScalarMult(pointHa, db);

    ECPoint::PrintECPoint(pointS1);
    ECPoint::PrintECPoint(pointS2);

    return 0;
}