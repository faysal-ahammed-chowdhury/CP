#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int b[n - 1];
    for(int i = 0; i + 1 < n; i++) {
        cin >> b[i];
    }
    vector<int> v;
    v.push_back(b[0]);
    for(int i = 1; i < n - 1; i++) {
        v.push_back(min(b[i], b[i - 1]));
    }
    if(n >= 2) {
        v.push_back(b[n - 2]);
    }
    for(auto i: v) {
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