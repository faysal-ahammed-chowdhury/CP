#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b, c; cin >> a >> b >> c;
    long long diff_ab = abs(a - b);
    long long diff_bc = abs(b - c);
    if((a + c) % 2 == 0 && ((a + c) / 2) % b == 0) {
        cout << "YES\n";
        return;
    }
    if(a >= b && (b - diff_ab) % c == 0 && (b - diff_ab) >= 0 && (b - diff_ab) != 0) {
        cout << "YES\n";
        return;
    }
    if(a <= b && (b + diff_ab) % c == 0  && (b + diff_ab) >= 0 && (b + diff_ab) != 0) {
        cout << "YES\n";
        return;
    }
    if(c >= b && (b - diff_bc) % a == 0 && (b - diff_bc) >= 0 && (b - diff_bc) != 0) {
        cout << "YES\n";
        return;
    }
    if(c <= b && (b + diff_bc) % a == 0 && (b + diff_bc) >= 0 && (b + diff_bc) != 0) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}