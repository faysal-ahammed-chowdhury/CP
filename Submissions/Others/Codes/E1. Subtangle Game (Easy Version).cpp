#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int a[N][N], b[N], l, n, m;
bool vis[N][N][N], dp[N][N][N];

bool f(int k, int i, int j) {
  if (k > l or i > n or j > m) {
    if (k & 1) return false;
    return true;
  }
  if (vis[k][i][j]) return dp[k][i][j];
  vis[k][i][j] = true;
  if (k & 1) {
    bool ans = f(k, i + 1, j);
    ans |= f(k, i, j + 1);
    if (b[k] == a[i][j]) {
      ans |= f(k + 1, i + 1, j + 1);
    }
    return dp[k][i][j] = ans;
  }
  bool ans = f(k, i + 1, j);
  ans &= f(k, i, j + 1);
  if (b[k] == a[i][j]) {
    ans &= f(k + 1, i + 1, j + 1);
  }
  return dp[k][i][j] = ans;
}

void solve() {
  cin >> l >> n >> m;
  for (int i = 1; i <= l; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int k = 1; k <= l; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        vis[k][i][j] = false;
      }
    }
  }
  cout << (f(1, 1, 1) == 0 ? "N" : "T") << '\n';
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