#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int idx = -1;
    char c = s[0];
    for(int i = 0; i < n; i++) {
        if(s[i] <= c) {
            idx = i;
            c = s[i];
        }
    }
    cout << c;
    for(int i = 0; i < n; i++) {
        if(i == idx) continue;
        cout << s[i];
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