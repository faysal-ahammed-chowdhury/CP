#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, mod = 1e9 + 7;

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

int inverse(int n) {
  return power(n, mod - 2, mod);
}

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int div_sum[N];
  memset(div_sum, 0, sizeof(div_sum));
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    for (int i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        div_sum[i] = (div_sum[i] + x) % mod;
        if (i != (x / i)) {
          div_sum[x / i] = (div_sum[x / i] + x) % mod;
        }
      }
    }
  }

  // exclusion dp (template code)
  int f[N], g[N];
  for (int i = N - 1; i >= 1; i--) {
    f[i] = 1ll * div_sum[i] * div_sum[i] % mod;
    g[i] = f[i];
    for (int j = i + i; j < N; j += i) {
      g[i] -= g[j];
      if (g[i] < 0) g[i] += mod;
    }
  }

  int ans = 0;
  for (int i = 1; i < N; i++) {
    ans = (ans + (1ll * g[i] * inverse(i))) % mod;
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("lcm.in", "r", stdin);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
// https://codeforces.com/gym/101992/problem/D