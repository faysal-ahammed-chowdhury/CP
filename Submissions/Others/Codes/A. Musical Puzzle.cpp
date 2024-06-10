#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map<string, int> mp;
    for(int i = 0; i < n - 1; i++) {
        char ch1, ch2;
        ch1 = s[i];
        ch2 = s[i + 1];
        string s2 = "";
        s2 += ch1;
        s2 += ch2;
        mp[s2]++;
    }
    cout << mp.size() << '\n';
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