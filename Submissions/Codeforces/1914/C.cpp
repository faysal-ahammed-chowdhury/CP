#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }

  int mx = 0;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    mx = max(mx, b[i]);
    if (i > k) break;
    int rem = k - i;
    int got = a[i] + (mx * rem);
    ans = max(ans, got);
  }
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