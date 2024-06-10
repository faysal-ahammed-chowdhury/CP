#include <bits/stdc++.h>
using namespace std;

void print(deque<int> q) {
  for (auto x: q) {
    cout << x << ' ';
  }
  cout << '\n';
}

void solve() {
    deque<int> q;
    q.push_back(2);
    q.push_back(4);
    cout << q[0] << '\n';
    print(q);
    q.pop_back();
    print(q);
    q.push_front(7);
    print(q);
    q.pop_front();
    print(q);
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