#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> mp1, mp2;
    for(auto i: s) {
        mp1[i]++;
    }
    int ans = max(mp1.size(), mp2.size());
    for(int i = 0; i < n; i++) {
        mp1[s[i]]--;
        mp2[s[i]]++;
        if(mp1[s[i]] == 0) {
            mp1.erase(s[i]);
        }
        int a = (int)mp1.size(), b = (int)mp2.size();
        ans = max(ans, a + b);
    }
    cout << ans << '\n';
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