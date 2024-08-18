#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int ans = n % 10;
  n /= 10;
  ans += n % 10;
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