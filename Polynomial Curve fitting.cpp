#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

class PolynomialFit {
private:
    int degree, N;
    vector<double> x, y, coefficients;

public:
    PolynomialFit(int degree, const vector<double>& x, const vector<double>& y) 
        : degree(degree), N(x.size()), x(x), y(y), coefficients(degree + 1, 0) {}

    void computeLeastSquares() {
        int n = degree + 1;  // Number of equations
        vector<vector<double>> B(n, vector<double>(n + 1, 0)); // Augmented matrix

        // Compute sums of powers of x
        vector<double> X(2 * degree + 1, 0);
        for (int i = 0; i < 2 * degree + 1; i++) {
            for (int j = 0; j < N; j++)
                X[i] += pow(x[j], i);
        }

        // Construct normal equations matrix
        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= degree; j++) {
                B[i][j] = X[i + j];
            }
        }

        // Compute sums of x^i * y
        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j < N; j++) {
                B[i][n] += pow(x[j], i) * y[j];
            }
        }

        // Solve using Gaussian Elimination
        for (int i = 0; i < n; i++) {
            // Pivoting to avoid division by zero
            for (int k = i + 1; k < n; k++) {
                if (abs(B[i][i]) < abs(B[k][i])) {
                    swap(B[i], B[k]);
                }
            }

            // Make diagonal elements 1 and eliminate other values in the column
            for (int k = i + 1; k < n; k++) {
                double factor = B[k][i] / B[i][i];
                for (int j = 0; j <= n; j++) {
                    B[k][j] -= factor * B[i][j];
                }
            }
        }

        // Back-substitution to get coefficients
        for (int i = n - 1; i >= 0; i--) {
            coefficients[i] = B[i][n];
            for (int j = i + 1; j < n; j++) {
                coefficients[i] -= B[i][j] * coefficients[j];
            }
            coefficients[i] /= B[i][i];
        }
    }

    void printPolynomial() {
        cout << "\nFitted Polynomial:\n";
        cout << "y = ";
        for (int i = 0; i <= degree; i++) {
            cout << (i == 0 ? "" : " + ") << "(" << fixed << setprecision(6) << coefficients[i] << ")x^" << i;
        }
        cout << "\n";
    }
};

int main() {
    int N, degree;
    cin >> N;

    vector<double> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    cin >> degree;

    if (degree >= N) {
        cout << "Error: Degree must be less than number of data points.\n";
        return 1;
    }

    PolynomialFit fit(degree, x, y);
    fit.computeLeastSquares();
    fit.printPolynomial();

    return 0;
}
