#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, y, r; cin >> n >> y >> r;
  int ans = min(n, r + (y / 2));
  cout << ans << '\n';
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