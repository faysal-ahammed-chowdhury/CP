#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, a[N], dp[N][2][2];

int fun(int i, int last, int first) {
  if (i == n + 1) return 0;
  if (i == n and last == 0 and first == 0) {
    return a[i];
  }
  else if (i == n) {
    return 0;
  }
  int &ans = dp[i][last][first];
  if (ans != -1) return ans;
  ans = fun(i + 1, 0, first);
  if (last == 0) {
    ans = max(ans, a[i] + fun(i + 1, 1, first));
  }
  return ans;
}

int cs = 0;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << "Case " << ++cs << ": " << max(fun(2, 0, 0), a[1] + fun(2, 1, 1)) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}