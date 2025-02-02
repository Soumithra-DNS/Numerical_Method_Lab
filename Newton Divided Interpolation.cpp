#include <bits/stdc++.h>
using namespace std;

class NewtonDividedInterpolation
{
private:
    int n;
    vector<double> x;
    vector<vector<double>> dividedDifferenceTable;

    void computeDividedDifferenceTable()
    {
        for (int col = 1; col < n; col++)
        {
            for (int row = 0; row < n - col; row++)
            {
                dividedDifferenceTable[row][col] =
                    (dividedDifferenceTable[row + 1][col - 1] - dividedDifferenceTable[row][col - 1]) /
                    (x[row + col] - x[row]);
            }
        }
    }

public:
    NewtonDividedInterpolation(const vector<double> &x, const vector<double> &y)
        : x(x), n(x.size())
    {
        dividedDifferenceTable.assign(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; i++)
        {
            dividedDifferenceTable[i][0] = y[i];
        }
        computeDividedDifferenceTable();
    }

    void displayTable()
    {
        cout << fixed << setprecision(6);
        cout << "Divided Difference Table:\n";
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n - row; col++)
            {
                cout << setw(12) << dividedDifferenceTable[row][col] << " ";
            }
            cout << endl;
        }
    }

    double interpolate(double value)
    {
        double result = dividedDifferenceTable[0][0];
        double term = 1.0;
        for (int i = 1; i < n; i++)
        {
            term *= (value - x[i - 1]);
            result += term * dividedDifferenceTable[0][i];
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

    NewtonDividedInterpolation interpolator(x, y);

    cout << "\n";
    interpolator.displayTable();

    double value;
    cin >> value;

    double result = interpolator.interpolate(value);
    cout << "\nInterpolated value at " << value << " is " << fixed << setprecision(6) << result << endl;

    return 0;
}
