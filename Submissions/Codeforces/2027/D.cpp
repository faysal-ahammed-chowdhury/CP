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
  cout << (ans >= inf ? -1 : ans) << '\n';
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