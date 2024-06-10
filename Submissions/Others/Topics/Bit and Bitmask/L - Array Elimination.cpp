#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        for(int j = 0; j < 30; j++) {
            if((x >> j) & 1) {
                mp[j]++;
            }
        }
    }
    set<int> se;
    for(int i = 1; i <= n; i++) {
        bool ok = true;
        for(auto j: mp) {
            if((j.second % i) != 0) {
                ok = false;
                break;
            }
        }
        if(ok) {
            se.insert(i);
        }
    }
    for(auto i: se) {
        cout << i << ' '; 
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