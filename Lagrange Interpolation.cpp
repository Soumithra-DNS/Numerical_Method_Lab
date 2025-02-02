#include <bits/stdc++.h>
using namespace std;

class Lagrange
{
private:
    int n;
    vector<double> x, y;

public:
    Lagrange(const vector<double> &x, const vector<double> &y) : x(x), y(y), n(x.size()) {}

    double interpolation(double value)
    {
        double result = 0.0;
        for (int i = 0; i < n; i++)
        {
            double term = y[i];
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    term *= ((value - x[j]) / (x[i] - x[j]));
            }
            result += term;
        }
        return result;
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

    double value;
    cin >> value;

    Lagrange lagrange(x, y);

    cout << fixed << setprecision(6) << lagrange.interpolation(value) << "\n";

    return 0;
}
