#include <iostream>
using namespace std;

void extended_euclidean_algorithm(int a, int b, int& gcd, int& x, int& y) {
    /*
    This function implements the Extended Euclidean algorithm to find the Bezout coefficients x and y for two integers a and b.
    */
    if (b == 0) {
        gcd = a;
        x = 1;
        y = 0;
    } else {
        int x1, y1;
        extended_euclidean_algorithm(b, a % b, gcd, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    int gcd, x, y;
    extended_euclidean_algorithm(a, b, gcd, x, y);
    cout << gcd << " " << x << " " << y << endl;
    return 0;
}

