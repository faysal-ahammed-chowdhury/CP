#include <bits/stdc++.h>
using namespace std;

const int N = 15, inf = 1e9;
int n, a[N][N], dp[(1 << N) + 2];

int fun(int mask) {
  if (mask == (1 << n) - 1) {
    return 0;
  }

  int &ans = dp[mask];
  if (ans != -1) return ans;

  ans = inf;
  for (int i = 0; i < n; i++) {
    if (!(mask & (1 << i))) {
      int val = a[i][i];
      for (int j = 0; j < n; j++) {
        if ((mask & (1 << j)) and i != j) {
          val += a[i][j];
        }
      }
      ans = min(ans, val + fun(mask | (1 << i)));
    }
  }
  return ans;
}

int cs = 0;
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  memset(dp, -1, sizeof(dp));
  cout << "Case " << ++cs << ": ";
  cout << fun(0) << '\n';
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