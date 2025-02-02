#include <bits/stdc++.h>
using namespace std;

class NewtonForwardInterpolation
{
private:
    int n;
    vector<double> x, y;
    vector<vector<double>> table;

    long long fact(int num)
    {
        long long res = 1;
        for (int i = 2; i <= num; i++)
            res *= i;
        return res;
    }



    void calculateTable()
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                table[j][i] = table[j + 1][i - 1] - table[j][i - 1];
            }
        }
    }

public:
    NewtonForwardInterpolation(const vector<double> &x, const vector<double> &y) : x(x), y(y), n(x.size())
    {
        table.assign(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; i++)
        {
            table[i][0] = y[i];
        }
        calculateTable();
    }

    double interpolate(double value)
    {
        double result = table[0][0];
        double h = x[1] - x[0];
        double p = (value - x[0]) / h;

        for (int i = 1; i < n; i++)
        {
            double term = table[0][i];
            for (int j = 0; j < i; j++)
            {
                term *= (p - j);
            }
            result += term / fact(i);
        }

        return result;
    }

    void displayTable()
    {
        cout << "\nForward Difference Table:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                cout << setw(12) << fixed << setprecision(6) << table[i][j] << " ";
            }
            cout << "\n";
        }
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

    NewtonForwardInterpolation interpolation(x, y);

    interpolation.displayTable();

    double value;
    cin >> value;

    double result = interpolation.interpolate(value);
    cout << "\nInterpolated value at x = " << value << " is " << fixed << setprecision(6) << result << "\n";

    return 0;
}
