#include <bits/stdc++.h>
using namespace std;

void print(multiset<int> se) {
    for (auto x: se) {
    cout << x << ' ';
    }
    cout <<'\n';
}

void solve() {
    multiset<int> se1;
    se1.insert(2);
    se1.insert(3);
    se1.insert(2);
    se1.insert(2);
    se1.insert(1);
    print(se1);
    auto se2 = se1;
    se1.erase(2);
    print(se1);
    se2.erase(se2.find(2));
    print(se2);
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