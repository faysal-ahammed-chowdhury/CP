#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    int x, y; cin >> x >> y;
    int res = INT_MAX;
    for(int m = 1; m <= 10; m++) {
            // cerr << m + 1 + (x - 1) / m << " " << (y - 1) / m << endl;
            int move = (m + 1 + (x - 1) / m + (y - 1) / m);
            res = min(res, move);
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}