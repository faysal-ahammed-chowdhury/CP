#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    long long n, k; cin >> n >> k;
    if (n % 2 == 0) {
        cout << "YES\n";
        return;
    }
    if (n % 2 == 1 && k % 2 == 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}