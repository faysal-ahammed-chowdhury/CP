#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> q;
  priority_queue<int> pq;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int x; cin >> x;
      pq.push(-x);
    }
    else {
      int x = pq.top();
      pq.pop();
      cout << -x << '\n';
    }
  }

  return 0;
}