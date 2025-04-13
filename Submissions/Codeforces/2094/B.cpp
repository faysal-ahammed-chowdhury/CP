#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m, l, r; cin >> n >> m >> l >> r;
  int x = abs(l), y = abs(r);

  if (m <= x) {
    cout << -m << ' ' << 0 << '\n';
    return;
  }

  if (m <= y) {
    cout << 0 << ' ' << m << '\n';
    return;
  }

  cout << -x << ' ' << -x + m << '\n';
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