#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    cout << log(16) << '\n'; // natural base log (e = 2.71...)
    cout << log2(32) << '\n'; // 2^5 = 32 => log2(32) = 5
    cout << log10(100) << '\n'; // 10^2 = 100 => log10(100) = 2
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