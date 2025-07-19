#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1], b[n + 1], c[n + 1], d[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int dibo1 = max(0ll, a[i] - c[i]);
    int dibo2 = max(0ll, b[i] - d[i]);
    int x = a[i] - dibo1;
    // cout << dibo1 << ' ' << dibo2 << ' ' << x << '\n';
    ans += dibo1;
    if (dibo2 > 0) ans += x + dibo2;;
  }

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