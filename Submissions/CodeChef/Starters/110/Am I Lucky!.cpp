#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, boys, k; cin >> n >> boys >> k;
  int girls = n - boys;
  int rem_boys = boys % k;
  int rem_girls = girls % k;

  int ans = abs(rem_boys - rem_girls);
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}