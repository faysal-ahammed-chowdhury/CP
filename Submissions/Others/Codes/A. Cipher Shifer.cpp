#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 0; i < n - 1; i++) {
        int start = i;
        i++;
        cout << s[start];
        while(s[start] != s[i]) {
            i++;
        }
    }
    cout << '\n';
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