#include <bits/stdc++.h>
using namespace std;

const int N = 105, MAX_SUM = 2005, inf = 1e9;
int n, a[N], tot;
bool dp[N][MAX_SUM * N];
bool vis[N][MAX_SUM * N];

bool fun(int i, int sum) {
  if (i == n + 1) return sum == (tot - sum);
  if (vis[i][sum]) return dp[i][sum];
  vis[i][sum] = true;
  bool ans = false;
  ans |= fun(i + 1, sum);
  ans |= fun(i + 1, sum + a[i]);
  return dp[i][sum] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  tot = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tot += a[i];
  }

  bool ans = fun(1, 0);
  if (!ans) {
    cout << 0 << '\n';
  }
  else {
    cout << 1 << '\n';
    while (1) {
      for (int i = 1; i <= n; i++) {
        if (a[i] & 1) {
          cout << i << '\n';
          return 0;
        }
        a[i] /= 2;
      }
    }
  }

  return 0;
}