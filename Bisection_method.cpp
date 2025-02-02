#include <bits/stdc++.h>
using namespace std;

class Bisection
{
private:
    double tol;
    int maxIt;
    double a, b;

    double func(double x)
    {
        return x * x * x - 4 * x - 9;
    }

    void gen()
    {
        int prev = 0;
        for (int i = 0;; i++)
        {
            if (func(i) >= 0)
            {
                a = prev;
                b = i;
                if (func(a) * func(b) < 0)
                    break;
            }
            prev = i;
        }
    }

public:
    Bisection(double tol, int maxIt) : tol(tol), maxIt(maxIt)
    {
        gen();
    }

    double findRoot()
    {
        double c;
        for (int i = 1; i <= maxIt; i++)
        {
            c = (a + b) / 2;
            double f_c = func(c);

            cout << "Iteration " << i << " - c: " << c << ", f(c): " << f_c << "\n";

            if (fabs(f_c) < tol)
            {
                cout << "Converged to root at iteration " << i << "\n";
                return c;
            }

            if (f_c * func(a) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
        }
        cout << "Maximum iterations reached. Approximate root: ";
        return c;
    }
};

int main()
{
    double tol = 1e-6;
    int maxIt = 100;

    Bisection bisection(tol, maxIt);
    double root = bisection.findRoot();

    cout << "Root: " << root << "\n";
    return 0;
}
