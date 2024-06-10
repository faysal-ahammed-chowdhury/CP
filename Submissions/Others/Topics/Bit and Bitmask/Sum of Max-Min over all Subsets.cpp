#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, mod = 1e9 + 7;
int a[N];

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
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += 1ll * a[i] * power(2, i - 1, mod) % mod;
    ans %= mod;
    ans -= 1ll * a[i] * power(2, n - i, mod) % mod;
    ans %= mod;
  }
  cout << ans << '\n';

  return 0;
}