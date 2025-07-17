#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 19;
ll dp[N][1024][10];

ll f(int i, int mask, int mx) {
  if (i <= 0) {
    // if (__builtin_popcount(mask) == mx) cout << mx << '\n';
    return __builtin_popcount(mask) == mx;
  }
  ll &ans = dp[i][mask][mx];
  if (ans != -1) return ans;
  ans = 0;
  for (int j = 0; j <= 9; j++) {
    if (j == 0 and __builtin_popcount(mask) == 0) continue;
    ans += f(i - 1, (mask | (1 << j)), max(mx, j));
  }
  return ans;
}

void solve() {
  string s; cin >> s;
  ll tmp = stol(s);
  int n = s.size();
  s = '.' + s;

  ll ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    ans += f(i, 0, 0);
  }
  // cout << ans << '\n';

  int mask = 0, mx = 0;
  for (int i = 0; i + 1 <= n; i++) {
    if (i > 0) {
      int x = s[i] - '0';
      mask |= (1 << x);
      mx = max(mx, x);
    }
    int nxt = s[i + 1] - '0';
    for (int j = 0; j < nxt; j++) {
      if (i == 0 and j == 0) continue;
      // cout << j << '\n';
      ans += f(n - i - 1, (mask | (1 << j)), max(mx, j));
    }
  }

  int x = s[n] - '0';
  mask |= (1 << x);
  mx = max(mx, x);

  if (__builtin_popcount(mask) == mx) ans++;

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}