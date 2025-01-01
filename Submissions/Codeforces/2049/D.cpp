#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 205;
const ll inf = 1e18;
int n, m, k, a[N][N];
ll dp[N][N][N][2];

ll f(int i, int j, int shift, bool has_shifted) {
  ll cost = 1ll * k * shift;
  if (i == n and j > m) return cost;
  if (i > n or j > m) return inf;
  int idx = ((j % m) + shift) % m;
  if (idx == 0) idx = m;
  ll &ans = dp[i][j][shift][has_shifted];
  if (ans != -1) return ans;
  ll here = min(-cost + f(i, j + 1, shift, true), f(i + 1, j, 0, false));
  ans = cost + a[i][idx] + here;
  if (!has_shifted) {
    if (shift + 1 < m) ans = min(ans, f(i, j, shift + 1, false));
  }
  // cout << i << ' ' << j << ' ' << shift << ' ' << has_shifted << ' ' << a[i][idx] << ' ' << here << ' ' << ans << '\n';
  return ans;
}

void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int jj = 0; jj <= m; jj++) {
        dp[i][j][jj][0] = -1;
        dp[i][j][jj][1] = -1;
      }
    }
  }
  cout << f(1, 1, 0, false) << '\n';
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