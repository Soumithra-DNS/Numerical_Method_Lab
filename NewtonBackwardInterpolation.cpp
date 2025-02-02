#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class NewtonBackwardInterpolation
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
            for (int j = n - 1; j >= i; j--)
            {
                table[j][i] = table[j][i - 1] - table[j - 1][i - 1];
            }
        }
    }

public:
    NewtonBackwardInterpolation(const vector<double> &x, const vector<double> &y)
        : x(x), y(y), n(x.size())
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
        double result = table[n - 1][0];
        double h = x[1] - x[0];
        double p = (value - x[n - 1]) / h;
        double pTerm = 1.0;

        for (int i = 1; i < n; i++)
        {
            pTerm *= (p + (i - 1));
            result += (pTerm * table[n - 1][i]) / fact(i);
        }
        return result;
    }

    void displayTable()
    {
        cout << "\nBackward Difference Table:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
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

    NewtonBackwardInterpolation interpolator(x, y);
    interpolator.displayTable();

    double value;
    cin >> value;

    double result = interpolator.interpolate(value);
    cout << "\nInterpolated value at x = " << value << " is " << fixed << setprecision(6) << result << endl;

    return 0;
}
