#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

double A(const double x, const int n, double a)
{
    double R = (-x * n) / (n + 1);
    a *= R;
    return a;
}

double S(const double x, const double eps, int& n, double s)
{
    n = 0;
    double a = x;
    s = a;
    do {
        n++;
        a = A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
    return s;
}

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:
        TEST_METHOD(TestS)
        {
            int n = 0;
            double s = 0;
            Assert::AreEqual(log(1.2), S(0.2, 0.0001, n, s), 0.001);
        }
    };
}