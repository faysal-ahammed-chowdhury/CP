#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    int x = (a[i] - (i - 1));
    x = max(0, x);
    ans = 1ll * ans * x % mod;
  }
  cout << ans << '\n';

  return 0;
}