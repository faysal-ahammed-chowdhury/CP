#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const double PI = (2 * acos(0.0));

void solve() {
    tuple<int, int, int, int> x;
    tuple<int, int, string> y;
    x = make_tuple(4, 1, 2, 3);
    cout << (get<0>(x)) << ' ' << (get<1>(x)) << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}