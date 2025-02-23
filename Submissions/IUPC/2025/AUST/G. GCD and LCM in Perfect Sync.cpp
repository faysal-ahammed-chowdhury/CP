#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

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

void solve() {
  int a, n; cin >> a >> n;

  vector<int> v;
  for (int i = 1; i * i <= a; i++) {
    if (a % i == 0) {
      v.push_back(i);
      if (i != (a / i)) v.push_back(a / i);
    }
  }

  int tmp = a;
  map<int, int> pf;
  for (int i = 2; i * i <= a; i++) {
    while (tmp % i == 0) {
      pf[i]++;
      tmp /= i;
    }
  }
  if (tmp > 1) pf[tmp]++;

  int ans = 1;
  for (auto [p, e] : pf) {
    int cnt = e + 1;

    int cur = 0, cur1 = 0, cur2 = 0;
    cur1 += power(cnt, n - 1, mod);
    cur1 %= mod;
    cur1 -= power(cnt - 1, n - 1, mod);
    if (cur1 < 0) cur1 += mod;

    cur2 -= power(cnt - 1, n - 1, mod);
    if (cur2 < 0) cur2 += mod;
    cur2 += power(cnt - 2, n - 1, mod);
    cur2 %= mod;

    cur = ((1ll * cur1 * cnt % mod) + (1ll * cur2 * (cnt - 2) % mod)) % mod;
    ans = 1ll * ans * cur % mod;
  }

  cout << ans << '\n';
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