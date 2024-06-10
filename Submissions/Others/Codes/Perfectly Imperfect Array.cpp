#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  bool ok = false;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    int sq = sqrt(x);
    while (sq * sq < x) sq++; 
    while (sq * sq > x) sq--; 
    if (sq * sq != x) ok = true;
  }

  cout << (ok ? "YES\n" : "NO\n");
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}