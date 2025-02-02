#include <bits/stdc++.h>
using namespace std;

class SecantMethod
{
private:
    double tol;
    int maxIt;

    double func(double x)
    {
        return x * x * x - 4 * x - 9;
    }

public:
    SecantMethod(double tol, int maxIt) : tol(tol), maxIt(maxIt) {}

    double findRoot(double x0, double x1)
    {
        for (int i = 0; i < maxIt; i++)
        {
            double f_x0 = func(x0);
            double f_x1 = func(x1);

            double x2 = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0);
            cout << "Iteration " << i + 1 << ": x = " << x2 << "\n";

            if (fabs(x2 - x1) < tol)
            {
                return x2;
            }

            x0 = x1;
            x1 = x2;
        }
        return x1;
    }
};

int main()
{
    double tol = 1e-6, x0 = -2.0, x1 = 3.0;
    int maxIt = 100;

    SecantMethod secantMethod(tol, maxIt);

    double root = secantMethod.findRoot(x0, x1);

    cout << "Root: " << root << "\n";

    return 0;
}
