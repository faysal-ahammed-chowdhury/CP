#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, q; cin >> n >> m >> q;
  set<int> se;
  for (int i = 1; i <= m; i++) {
    int x; cin >> x;
    se.insert(x);
  }
  while (q--) {
    int x; cin >> x;
    auto it = se.lower_bound(x);
    if (it == se.begin()) {
      cout << *se.begin() - 1 << '\n';
    }
    else if (it == se.end()) {
      cout << n - *se.rbegin() << '\n';
    }
    else {
      cout << (*it - *(--it)) / 2 << '\n';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}