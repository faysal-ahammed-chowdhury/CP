#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9, inf = 1e9;
int n, m, k, tmp;
int cost[N];

int f(int i, int j, int k, vector<vector<int>> &a, vector<vector<int>> &dp) {
  if (i == 1 and j == 1) {
    assert(k == 1);
    return (tmp + a[i][j] - cost[k]);
  }
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  ans = -inf;
  if (i - 1 >= 1) {
    int x = f(i - 1, j, k - 1, a, dp);
    if (x >= 0) ans = max(ans, (a[i][j] - cost[k]) + x);
  }
  if (j - 1 >= 1) {
    int x = f(i, j - 1, k - 1, a, dp);
    if (x >= 0) ans = max(ans, (a[i][j] - cost[k]) + x);
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  k = n + m - 1;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= k; i++) {
    cin >> cost[i];
  }

  int l = 0, r = 1e15, ans = -inf;
  while (l <= r) {
    int mid = (l + r) / 2;

    tmp = mid;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    bool ok = false;
    for (int i = 1; i <= n; i++) {
      int d = i;
      int j = 1 + (k - d);
      if (j <= m) {
        int here = f(i, j, k, a, dp);
        if (here >= 0) {
          ok = true;
          break;
        }
      }
    }

    if (ok) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }

  cout << ans << '\n';

  return 0;
}