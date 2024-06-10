#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;

  int now = 0;
  for (int i = 1; i <= n; i *= 2) {
    int x = (n + i) / (i * 2);
    if (k <= x + now) {
      int here = k - now;
      cout << i + (here - 1) * (i * 2) << '\n';
      return;
    }
    now += x;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}