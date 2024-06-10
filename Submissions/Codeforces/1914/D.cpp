#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 9, inf = 1e18;
int n, a[N], b[N], c[N];
int dp[N][2][2][2];

int fun(int i, int p, int q, int r) {
  if (i == n + 1) {
    if (p and q and r) return 0;
    return -inf;
  }
  int &ans = dp[i][p][q][r];
  if (ans != -1) return ans;
  ans = fun(i + 1, p, q, r);
  if (p == 0) {
    ans = max(ans, a[i] + fun(i + 1, 1, q, r));
  }
  if (q == 0) {
    ans = max(ans, b[i] + fun(i + 1, p, 1, r));
  }
  if (r == 0) {
    ans = max(ans, c[i] + fun(i + 1, p, q, 1));
  }
  return ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 2; l++) {
          dp[i][j][k][l] = -1;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  cout << fun(1, 0, 0, 0) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}