#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    int n, x1, y1, x2, y2; cin >> n >> x1 >> y1 >> x2 >> y2;
    int my_min = min({x1, n - x1 + 1, y1, n - y1 + 1});
    int des_min = min({x2, n - x2 + 1, y2, n - y2 + 1});
    cout << abs(my_min -  des_min) << '\n';
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