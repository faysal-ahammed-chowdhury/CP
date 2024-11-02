#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 998244353;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int cnt = i * (n - i + 1);
    a[i] *= cnt;
  }
  sort(a + 1, a + n + 1);
  int b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  sort(b + 1, b + n + 1);
  reverse(b + 1, b + n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (a[i] % mod) * (b[i] % mod) % mod;
    ans %= mod;
  }
  cout << ans << '\n';

  return 0;
}