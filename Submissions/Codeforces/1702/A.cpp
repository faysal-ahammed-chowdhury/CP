#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int ex = log10(n);
  int ans = n - pow(10, ex);
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