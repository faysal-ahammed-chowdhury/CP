#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int count_Qmark(string s) {
    int cnt = 0;
    for (auto i : s) if (i == '?') cnt++;
    return cnt;
}

void solve() {
    string s; cin >> s;
    int cnt = count_Qmark(s);
    if (s[0] == '0') cout << 0 << '\n';
    else if (cnt == 0) cout << 1 << '\n';
    else {
        int ans = pow(10, cnt - 1);
        if (s[0] == '?') ans *= 9;
        else ans *= 10;
        cout << ans << '\n';
    }
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
