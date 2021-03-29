#include <iostream>
#include <cmath>

double find_root(double f(double), double a, double b, double tol)
{
    double middle = (a + b) / 2;
    if ((abs(f(middle - tol)) <= 1e-6) && (abs(f(middle + tol)) <= 1e-6))
       return middle;
    else if (f(middle)*f(a) < 0)
       return find_root(f, a, middle, tol);
    else
        return find_root(f, middle, b, tol);
}
int main()
{
    return 0;
}

