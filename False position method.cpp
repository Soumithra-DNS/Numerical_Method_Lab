#include <bits/stdc++.h>
using namespace std;

class False_position
{
private:
    int maxIt;
    double a, b, tol;

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
    False_position(double tol, int maxIt) : tol(tol), maxIt(maxIt)
    {
        gen();
    }

    double findRoot()
    {
        double c = 0;
        for (int i = 0; i < maxIt; i++)
        {
            c = a - (func(a) * (b - a) / (func(b) - func(a)));
            double f_c = func(c);
            cout << "Iteration " << i + 1 << " = " << c << "\n";
            if (fabs(f_c) < tol)
            {
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
        return c;
    }
};

int main()
{
    double tol = 1e-6;
    int maxIt = 100;

    False_position false_position(tol, maxIt);
    double root = false_position.findRoot();
    cout << "Root: " << root << "\n";
}
