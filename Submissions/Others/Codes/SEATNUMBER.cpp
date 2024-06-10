#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s1, s2;
    if(n <= 15) {
        s1 = "Lower";
    }
    else {
        s1 = "Upper";
    }
    if(n <= 10 || (n >= 16 && n <= 25)) {
        s2 = "Double";
    }
    else {
        s2 = "Single";
    }
    cout << s1 << ' ' << s2 << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
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