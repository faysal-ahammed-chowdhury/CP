#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n; string s; char ch; cin >> n >> ch >> s;
    int idx = 0;
    while (s[idx] >= ch) {
        idx++;
    }
    for (int i = 0; i < n; i++) {
        if (i == idx) cout << ch;
        cout << s[i];
    }
    if (idx >= n) cout << ch;
    cout << '\n';
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