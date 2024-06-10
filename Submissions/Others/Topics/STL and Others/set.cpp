#include <bits/stdc++.h>
using namespace std;

void solve() {
    set<int> se;
    se.insert(3);
    se.insert(2);
    auto it = se.begin();
    cout << (*it) << '\n';
    ++it;
    cout << (*it) << '\n';
    se.insert(3);
    for (auto x: se) {
    cout << x << ' ';
    }
    cout <<'\n';
    se.insert(1);
    se.insert(1);
    se.insert(2);
    for (auto x: se) {
    cout << x << ' ';
    }
    cout <<'\n';
    // min_value
    cout << (*se.begin()) << '\n';

    // max_value
    cout << *(--se.end()) << '\n';

    se.erase(se.begin());
    for (auto x: se) {
    cout << x << ' ';
    }
    cout <<'\n';
    se.erase(3);
    for (auto x: se) {
    cout << x << ' ';
    }
    cout <<'\n';

    se.insert(5);
    it = se.find(5);
    if (it != se.end()) {
    cout << "5 exists\n";
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