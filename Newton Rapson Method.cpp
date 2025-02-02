#include <bits/stdc++.h>
using namespace std;

class NewtonRaphson
{
private:
    double tol;
    int maxIt;
    double value;

    double func(double x)
    {
        return x * x * x - 4 * x - 9;
    }

    double derivative(double x)
    {
        return 3 * x * x - 4;
    }

    void gen()
    {
        for (int i = 0;; i++)
        {
            if (func(i) > 0)
            {
                value = i - 1;
                break;
            }
        }
    }

public:
    NewtonRaphson(double tol, int maxIt) : tol(tol), maxIt(maxIt)
    {
        gen();
    }

    double findRoot()
    {
        double xNew;
        for (int i = 1; i <= maxIt; i++)
        {
            double fValue = func(value);
            double fDerivative = derivative(value);

            if (fabs(fDerivative) < numeric_limits<double>::epsilon())
            {
                cerr << "Error: Derivative is too small to continue.\n";
                return numeric_limits<double>::quiet_NaN();
            }

            xNew = value - (fValue / fDerivative);
            cout << "Iteration " << i << ": x = " << xNew << "\n";

            if (fabs(xNew - value) < tol)
            {
                return xNew;
            }

            value = xNew;
        }

        cerr << "Error: Method did not converge within the maximum iterations.\n";
        return numeric_limits<double>::quiet_NaN();
    }
};

int main()
{
    double tol = 1e-6;
    int maxIt = 100;

    NewtonRaphson newtonRaphson(tol, maxIt);
    double root = newtonRaphson.findRoot();

    cout << "Root: " << root << "\n";

    return 0;
}
