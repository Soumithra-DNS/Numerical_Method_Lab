#include <bits/stdc++.h>
using namespace std;

class LeastSquareCurve
{
private:
    double a0, a1;
    vector<double> x, y;
    int n;

public:
    LeastSquareCurve(const vector<double> &x, const vector<double> &y) : x(x), y(y), n(x.size()), a0(0), a1(0) {}

    void computeLeastSquares()
    {
        double sumX = 0, sumY = 0, sumXY = 0, sumXX = 0;
        for (int i = 0; i < n; i++)
        {
            sumX += x[i];
            sumY += y[i];
            sumXY += (x[i] * y[i]);
            sumXX += (x[i] * x[i]);
        }

        a1 = (n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX);
        a0 = (sumY - a1 * sumX) / n;
    }

    void print()
    {
        cout << "Y = " << fixed << setprecision(6) << a0
            << ((a1 >= 0) ? " + " : " - ") << abs(a1) << "X" << "\n";
    }
};

int main()
{
    int n;
    cin >> n;

    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    LeastSquareCurve Curve(x, y);
    Curve.computeLeastSquares();
    Curve.print();

    return 0;
}
