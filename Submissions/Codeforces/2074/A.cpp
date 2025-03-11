#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int l, r, u, d; cin >> l >> r >> u >> d;
  if (l == r and u == d and (l + r) == (u + d)) cout << "YES\n";
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