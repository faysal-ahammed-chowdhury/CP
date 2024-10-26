#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5 + 9, inf = 1e18;
int n, m, a[N], b[N], psum[N];

int f(int i, int k, vector<vector<int>> &dp) {
  if (i > n) return 0;
  if (k > m) return inf;
  int &ans = dp[i][k];
  if (ans != -1) return ans;
  ans = f(i, k + 1, dp);
  int idx = upper_bound(psum + i, psum + n + 1, psum[i - 1] + b[k]) - &psum[0];
  if (i < idx) ans = min(ans, (m - k) + f(idx, k, dp));
  return ans;
}

int f2(int i, int k, vector<vector<int>> &dp) {
  if (k == m) return n - k + 1;
  if (i > n) return 1;
  int ans = f(i, k, dp);
  int ans1 = f(i, k + 1, dp);
  int idx = upper_bound(psum + i, psum + n + 1, psum[i - 1] + b[k]) - &psum[0];
  int ans2 = inf;
  if (i < idx) ans2 = (m - k) + f(idx, k, dp);
  int ret = 0;
  if (ans == ans1) ret += f2(i, k + 1, dp);
  if (ans == ans2) ret += f2(idx, k, dp);
  // cout << i << ' ' << k << ' ' << idx << '\n';
  return ret;
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    psum[i] = psum[i - 1] + a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  vector<vector<int>> dp(n + 5, vector<int>(m + 1, -1));
  int ans = f(1, 1, dp);
  if (ans >= inf) {
    cout << -1 << '\n';
    return;
  }
  cout << ans << ' ' <<  f2(1, 1, dp) << '\n';
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