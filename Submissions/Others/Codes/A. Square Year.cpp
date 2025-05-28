#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int sq = sqrt(n);
  if (sq * sq < n) sq++;
  if (sq * sq > n) sq--;

  if (sq * sq == n) cout << 0 << ' ' << sq << '\n';
  else cout << -1 << '\n';
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