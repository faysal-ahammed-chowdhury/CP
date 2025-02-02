#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  set<int> se1, se2;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    se1.insert(x);
  }
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    se2.insert(x);
  }

  if (se1.size() >= 3 or se2.size() >= 3 or (se1.size() >= 2 and se2.size() >= 2)) {
    cout << "YES\n";
  }
  else cout << "NO\n";
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