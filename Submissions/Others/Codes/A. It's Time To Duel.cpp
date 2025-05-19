#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  bool all_one = true, ok = true;
  int last = -1;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    all_one &= x == 1;
    if (last == 0 and last == x) ok = false;
    last = x;
  }

  ok &= !all_one;

  if (ok) cout << "NO\n";
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