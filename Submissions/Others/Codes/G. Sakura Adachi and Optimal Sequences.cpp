#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9, mod = 1e6 + 3;
int32_t n, a[N], b[N];
int32_t dp[1000005][22];
int32_t fact[1000005], ifact[1000005];

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

int inverse(int x) {
  return power(x, mod - 2, mod);
}

void prec() {
  fact[0] = 1;
  for (int i = 1; i < 1000005; i++) {
    fact[i] = 1ll * fact[i - 1] * i % mod;
  }
  ifact[1000005 - 1] = inverse(fact[1000005 - 1]);
  for (int i = 1000005 - 2; i >= 0; i--) {
    ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
  }
}

int calc(int x, int y, int k) {
  if (dp[x][k] == -1 or dp[x][k] > y) return -1;
  int rem = y - dp[x][k];
  int ans = 0;
  for (int i = k; i >= 1; i--) {
    int cur = dp[1][i];
    ans += rem / cur;
    rem -= (rem / cur) * cur;
  }
  ans += rem;
  return ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  int mn = 1e18, second_op = -1;
  for (int k = 0; k <= 20; k++) {
    bool ok = true;
    int tot = 0;
    for (int i = 1; i <= n; i++) {
      int cur = calc(a[i], b[i], k);
      if (cur == -1) {
        ok = false;
        break;
      }
      tot += cur;
    }
    if (ok) {
      tot += k;
      mn = min(mn, tot);
      if (mn == tot) {
        second_op = k;
      }
    }
  }

  vector<int> op[n + 1];
  for (int i = 1; i <= n; i++) {
    int rem = b[i] - dp[a[i]][second_op];
    int ans = 0;
    for (int j = second_op; j >= 1; j--) {
      int cur = dp[1][j];
      ans += rem / cur;
      op[i].push_back(rem / cur);
      rem -= (rem / cur) * cur;
    }
    op[i].push_back(rem);
    ans += rem;
  }

  int ways = 1;
  for (int j = 0; j < op[1].size(); j++) {
    int cur = 1, tot = 0;
    for (int i = 1; i <= n; i++) {
      tot += op[i][j];
      cur = 1ll * cur * inverse(fact[op[i][j]]) % mod;
      // cout << fact[op[i][j]] << '\n';
    }
    cur = 1ll * cur * (tot < mod ? fact[tot] : 0) % mod;
    ways = 1ll * ways * cur % mod;
  }

  cout << mn << ' ' << ways << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();
  
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= 1000000; i++) {
    int x = i;
    for (int k = 0; k <= 20; k++) {
      dp[i][k] = x;
      x += x;
      if (x > 1000000) break;
    }
  }

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}