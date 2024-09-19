#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

int cs;
void solve() {
  int n, m; cin >> n >> m;
  int nn = n;
  map<int, int> pf;
  for (int i = 2; 1ll * i * i <= nn; i++) {
    while (n % i == 0) {
      pf[i]++;
      n /= i;
    }
  }
  if (n > 1) pf[n]++;

  int ans = 1;
  for (auto [p, ex] : pf) {
    int e = ((1ll * ex * m) + 1) % (mod - 1);
    int x = power(p, e, mod) - 1;
    if (x < 0) x += mod;
    int y = power(p - 1, mod - 2, mod);
    ans = 1ll * ans * (1ll * x * y % mod) % mod;
  }
  cout << "Case " << ++cs << ": " << ans << '\n';
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