#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int power(int b, int p, int m) {
  if(p == 0) return 1 % m;
  if(p & 1) {
    int val = power(b, p / 2, m);
    return ((1LL * val * val) % m) * b % m;
  }
  else {
    int val = power(b, p / 2, m);
    return (1LL * val * val) % m;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int k = 0; k < 30; k++) {
    int cnt1 = 0, cnt0 = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] & (1 << k)) {
        cnt1++;
      }
      else {
        cnt0++;
      }
    }
    if (cnt1 == 0) continue;
    ans += 1ll * (power(2, cnt1, mod) - 1) * (1 << k) % mod;
    ans %= mod;
  }
  cout << ans << '\n';

  return 0;
}