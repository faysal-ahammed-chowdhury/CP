#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    double n = 10.56;
    cout << ceil(n) << '\n';
    cout << floor(n) << '\n';
    cout << round(n) << '\n';
    cout << llround(n) << '\n'; // for long long
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