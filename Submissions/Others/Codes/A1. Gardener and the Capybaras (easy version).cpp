#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();
    set<char> se;
    for(auto i: s) {
        se.insert(i);
    }
    if(se.size() == 1) {
        for(auto i: s) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
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