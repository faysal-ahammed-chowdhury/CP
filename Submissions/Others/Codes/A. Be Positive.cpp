#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n; cin >> n;
  int zero = 0, one = 0, neg = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    zero += x == 0;
    one += x == 1;
    neg += x == -1;
  }

  int ans = zero;
  if (neg & 1) ans += 2;
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