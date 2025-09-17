#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int b[k + 1];
  for (int i = 1; i <= k; i++) {
    cin >> b[i];
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  sort(b + 1, b + k + 1);

  int ans = 0, i = 1;
  for (int j = 1; j <= k; j++) {
    int x = b[j];
    for (int it = 1; it <= x - 1 and i <= n; it++, i++) {
      ans += a[i];
      // cout << i << ' ' << a[i] << '\n';
    }
    i++;
  }

  for (;i <= n; i++) {
    ans += a[i];
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