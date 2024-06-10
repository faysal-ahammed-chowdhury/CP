#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, inf = 1e9;
int n, a[N], dp[N];

int fun(int i) {
  if (i == n + 1) return 0;
  int &ans = dp[i];
  if (ans != -1) return ans;
  ans = inf;
  if (i + a[i] <= n) {
    ans = fun(i + 1 + a[i]);
  }
  ans = min(ans, 1 + fun(i + 1));
  return ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = -1;
  }
  cout << fun(1) << '\n';
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