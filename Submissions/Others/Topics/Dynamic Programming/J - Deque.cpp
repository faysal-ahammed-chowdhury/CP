#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 3005;
int n, a[N];
ll dp[2][N][N];

ll fun(int last, int i, int j) {
  if (i > j) return 0;
  ll &ans = dp[last][i][j];
  if (ans != -1) return dp[last][i][j];
  ans = 0;
  if (last == 0) {
    ll ans1 = a[i] + fun(!last, i + 1, j);
    ll ans2 = a[j] + fun(!last, i, j - 1);
    ans = max(ans1, ans2);
  }
  else {
    ll ans1 = -a[i] + fun(!last, i + 1, j);
    ll ans2 = -a[j] + fun(!last, i, j - 1);
    ans = min(ans1, ans2);
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  cout << fun(0, 1, n) << '\n';

  return 0;
}