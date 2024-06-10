#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    cout << abs(-5.5) << '\n'; // return absolute (remove the sign) number
    cout << sqrt(49) << '\n'; // return square root [O(logn)]
    cout << cbrt(27) << '\n'; // return cubic root [O(logn)]
    cout << pow(2, 5) << '\n'; // like 2^5 [O(n)]
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}