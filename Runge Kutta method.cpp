#include <bits/stdc++.h>
using namespace std;

class RungeKutta
{
private:
    double x0, y0, h, x;

    double func(double x, double y)
    {
        return x + y * y;
    }

public:
    RungeKutta(double x0, double y0, double h, double x) : x0(x0), y0(y0), h(h), x(x) {}

    void solve()
    {
        double k1, k2, k3, k4;

        while (x0 + h <= x)
        {
            k1 = h * func(x0, y0);
            k2 = h * func(x0 + 0.5 * h, y0 + 0.5 * k1);
            k3 = h * func(x0 + 0.5 * h, y0 + 0.5 * k2);
            k4 = h * func(x0 + h, y0 + k3);

            y0 += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
            x0 += h;
            cout << y0 << "\n";
        }

        cout << fixed << setprecision(5) << y0 << "\n";
    }
};

int main()
{
    double x0, y0, h, x;
    cin >> x0 >> y0 >> h >> x;
    RungeKutta kutta(x0, y0, h, x);
    kutta.solve();
    return 0;
}
