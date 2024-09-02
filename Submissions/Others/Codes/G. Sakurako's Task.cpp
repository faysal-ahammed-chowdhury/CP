#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n, k; cin >> n >> k;
  if (n == 1) {
    int x; cin >> x;
    int ans = k - 1;
    if (x <= k - 1) ans = k;
    cout << ans << '\n';
    return;
  }
  int gc = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    gc = __gcd(gc, x);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int mx = gc * (i - 1);
    int need = mx + 1 - i;
    int tmp = k;
    if (tmp > need) {
      tmp -= need;
      ans = max(ans, mx + tmp);
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}