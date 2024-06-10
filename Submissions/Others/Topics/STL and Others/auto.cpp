#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> v({1, 2, 3});
    for(auto it = v.begin(); it != v.end(); it++) {
      cout << *it << '\n';
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