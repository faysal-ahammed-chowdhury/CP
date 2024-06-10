#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

ll get(ll n) {
  return (1ll * n * (n + 1)) / 2;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  n++;

  int ans = 0;
  for (int i = k; i <= n; i++) {
    ll l = get(i - 1);
    ll r = get(n - 1) - get(n - 1 - i);
    ans = (ans + (r - l + 1) % mod) % mod;
  }
  cout << ans << '\n';

  return 0;
}