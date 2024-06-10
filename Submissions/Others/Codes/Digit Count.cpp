#include <bits/stdc++.h>
using namespace std;

const int N = 11;
int a[N], n, m, dp[N][N];

int fun(int i, int last) {
  if (i == n + 1) {
    return 1;
  }
  int &ans = dp[i][last];
  if (ans != -1) return ans;
  ans = 0;
  for (int j = 1; j <= m; j++) {
    if (last == -1) {
      ans += fun(i + 1, a[j]);
    }
    else if (abs(a[j] - last) <= 2) {
      ans += fun(i + 1, a[j]);
    }
  }
  return ans;
}

int cs = 0;
void solve() {
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << "Case " << ++cs << ": ";
  cout << fun(1, -1) << '\n';
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