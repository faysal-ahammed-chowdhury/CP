#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n, k; cin >> n >> k;
  int ans = 0, sum = 0, mx = 0;
  for (int i = 1; i <= k; i++) {
    int x; cin >> x;
    ans += x - 1;
    sum += x;
    mx = max(mx, x);
  }
  sum -= mx;
  ans += sum;
  ans -= mx - 1;
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