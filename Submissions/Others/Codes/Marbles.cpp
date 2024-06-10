#include <iostream>
using namespace std;

unsigned long long combination(int n, int k) {
    if (k > n - k) {
        k = n - k;  // Optimize by calculating smaller value ()
    }

    unsigned long long result = 1;
    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        // Convert the problem to selecting (k - 1) marbles from (n - 1) marbles
        // because we're ensuring that at least one marble of each color is selected
        cout << combination(n - 1, k - 1) << '\n';
    }

    return 0;
}
