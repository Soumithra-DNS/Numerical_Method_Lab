#include <bits/stdc++.h>
using namespace std;

class EulerMethod {
private:
    double x0, y0, h, x;

    double func(double x, double y) {
        return x + y + x * y;
    }

public:
    EulerMethod(double x0, double y0, double h, double x) : x0(x0), y0(y0), h(h), x(x) {}

    void solve() {
        while (x0 < x) {
            y0 = y0 + h * func(x0, y0);
            x0 = x0 + h;
        }
        cout << fixed << setprecision(5) << y0 << "\n";
    }
};

int main() {
    double x0, y0, h, x;
    cin >> x0 >> y0 >> h >> x;

    EulerMethod euler(x0, y0, h, x);
    euler.solve();

    return 0;
}
