#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const double PI = (2 * acos(0.0));

void solve() {
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.front() << '\n';
    q.pop();
    cout << q.front() << '\n';
    cout << q.size() << '\n';
    cout << q.empty() << '\n';
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