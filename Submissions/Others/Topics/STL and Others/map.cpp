#include <bits/stdc++.h>
using namespace std;

void solve() {
    map<int, string> mp;
    mp[2] = "two";
    mp[100] = "hundred";
    mp[2] = "twwwwo";
    mp[3] = "three";
    auto it = mp.begin();
    cout << (*it).first << ' ' << (*it).second << '\n';
    cout << it -> first << ' ' << it -> second << '\n';
    for (auto it = mp.begin(); it != mp.end(); it++) {
      cout << it -> first << ' ' << it -> second << '\n';
    }
    for (auto x: mp) {
      cout << x.first << ' ' << x.second << '\n';
    }
    cout << mp[3] << '\n';
    cout << mp.size() << '\n';
    mp[4];
    cout << mp.size() << '\n';


    map<int, int> m;
    m[1]++;
    m[3] = 2;
    cout << m[1] << '\n';
    if (m.find(1) != m.end()) {
      cout << "1 exists\n";
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
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}