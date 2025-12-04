#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 9, mod = 998244353;
int mx_l[N];
int dp[N], pref[N];

void solve() {
  int n, m; cin >> n >> m;
  n++;
  for (int i = 0; i <= n; i++) {
    mx_l[i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    int l, r; cin >> l >> r;
    mx_l[r] = max(mx_l[r], l);
  }

  for (int i = 1; i <= n; i++) {
    mx_l[i] = max(mx_l[i], mx_l[i - 1]);
  }

  dp[1] = 2;
  pref[1] = 2;
  for (int i = 2; i <= n; i++) {
    int j = mx_l[i - 1] + 1;
    dp[i] = pref[i - 1] - pref[j - 1];
    if (dp[i] < 0) dp[i] += mod;
    pref[i] = (pref[i - 1] + dp[i]) % mod;
  }

  cout << dp[n] << '\n';
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