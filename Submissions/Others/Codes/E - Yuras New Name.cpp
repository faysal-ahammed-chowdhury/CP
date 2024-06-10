#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    string s; cin >> s;
    int n = s.length();
    if (n == 1 && s[0] == '^') {
        cout << 1 << '\n';
        return;
    }
    int consecutive = 0;
    int ans = 0;
    bool first = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == '_') consecutive++;
        else {
            ans += ((consecutive - 1) < 0 ? 0 : consecutive - 1);
            consecutive = 0;
            if (first == true && s[0] == '_') {
                ans++;
            }
            first = false;
        }
    }
    if (s[n - 1] == '_') ans += consecutive;
    if (first) ans++;
    cout << ans << '\n';
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