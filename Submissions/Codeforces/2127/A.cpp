#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  bool all_same = true;
  bool has_zero = false;

  set<int> se;

  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x == -1) continue;
    se.insert(x);
    has_zero |= x == 0;
  }
  if (has_zero or se.size() > 1) cout << "NO\n";
  else cout << "YES\n";
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