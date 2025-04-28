#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  ll sum = 0, odd = 0;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    sum += x;
    odd += x & 1;
    mx = max(mx, x);
  }
  ll ans = sum - odd + 1;
  if (odd == 0 or odd == n) ans = mx;
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