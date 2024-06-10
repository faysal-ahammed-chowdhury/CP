#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int bit = 0;
    map<char, int> mp;
    for(char c: s) {
        if(mp.find(c) != mp.end()) {
            if(mp[c] != bit) {
                cout << "NO\n";
                return;
            }
        }
        mp[c] = bit;
        bit = !bit;
    }
    cout << "YES\n";
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