#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  set<int> one, two, common;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x <= k) {
      one.insert(x);
    }
  }
  for (int i = 1; i <= m; i++) {
    int x; cin >> x;
    if (x <= k) {
      two.insert(x);
    }
    if (one.find(x) != one.end()) {
      common.insert(x);
    }
  }

  int x = one.size() - common.size();
  int y = two.size() - common.size();
  int z = common.size();

  if (x < (k / 2)) {
    z -= (k / 2) - x;
  }
  if (y < (k / 2)) {
    z -= (k / 2) - y;
  }

  if (z >= 0) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}