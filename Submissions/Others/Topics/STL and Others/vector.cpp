#include <bits/stdc++.h>
using namespace std;

void solve() {
    // vector<int> v(10);
    vector<int> v({1, 1, 5, 5, 4, 2});
    for(auto i : v) {
        cout << i << ' ';
    }
    cout << '\n';
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << (*it) << ' ';
    }
    cout << '\n';

    auto it = std::unique(v.begin(), v.end());
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << (*it) << ' ';
    }
    cout << '\n';
    cout << distance(v.begin(), it) << '\n';
    v.resize(distance(v.begin(), it));
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << (*it) << ' ';
    }
    cout << '\n';
    sort(v.begin(), v.end());
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << (*it) << ' ';
    }
    cout << '\n';
    reverse(v.begin(), v.end());
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << (*it) << ' ';
    }
    cout << '\n';
    v.erase(v.begin());
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << (*it) << ' ';
    }
    cout << '\n';
    v.erase(v.begin(), v.begin() + 2);
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << (*it) << ' ';
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
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}