#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int N = 17, inf = 1e9;
int n, a[N], b[N], same_line[N][N], dp[(1 << N) + 2];

int fun(int mask) {
  if (__builtin_popcount(mask) == n) return 0;
  if (__builtin_popcount(mask) >= n - 2) return 1;

  int &ans = dp[mask];
  if (ans != -1) return ans;
  ans = inf;

  for (int i = 1; i <= n; i++) {
    if (!CHECK(mask, i)) {
      int new_mask = mask | (1 << i);
      for (int j = 1; j <= n; j++) {
        if (!CHECK(new_mask, j)) {
          SET(new_mask, j);
          new_mask |= same_line[i][j];
          ans = min(ans, 1 + fun(new_mask));
          break;
        }
      }
    }
  }
  return ans;
}

int cs;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int tmp = 0;
      tmp |= (1 << i), tmp |= (1 << j);
      for (int k = 1; k <= n; k++) {
        if ((b[j] - b[i]) * (a[k] - a[j]) == (b[k] - b[j]) * (a[j] - a[i])) {
          SET(tmp, k);
        }
      }
      same_line[i][j] = tmp;
    }
  }

  int x = (1 << n);
  memset(dp, -1, sizeof dp);
  int ans = fun(0);
  cout << "Case " << ++cs << ": ";
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