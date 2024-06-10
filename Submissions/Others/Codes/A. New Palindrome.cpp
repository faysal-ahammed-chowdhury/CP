#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.length();
    map<char, int> mp;
    for(auto i: s) {
        mp[i]++;
    }
    if(n == 1 || n == 3) {
        cout << "NO\n";
    }
    else if(n == 2) {
        if(mp.size() == 1) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
    else {
        int count = 0;
        for(auto i: mp) {
            if(i.second >= 2) {
                count++;
            }
        }
        if(count >= 2) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
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