#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5005, mod = 998244353;
int n, target;
int a[N], dp[1030];

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

int E(int x) {
  if (x == target) return 0;
  int &ans = dp[x];
  if (ans != -1) return ans;
  int k = 0;
  for (int i = 1; i <= n; i++) {
    if ((x | a[i]) == x) k++;
  }
  int sum = 1, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if ((x | a[i]) == x) continue;
    if ((x | target | a[i]) != target) continue;
    sum += 1ll * (1ll * power(n, mod - 2, mod) % mod) * E(x | a[i]) % mod;
    sum %= mod;
  }
  int div = 1ll * (n - k) * power(n, mod - 2, mod) % mod;
  return ans = (1ll * sum * power(div, mod - 2, mod) % mod);
}

void solve() {
  cin >> n >> target;
  int orr = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if ((a[i] | target) == target) orr |= a[i];
  }

  if (orr != target) {
    cout << -1 << '\n';
    return;
  }

  memset(dp, -1, sizeof dp);
  int ans = E(0);
  assert(ans >= 0 and ans < mod);
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