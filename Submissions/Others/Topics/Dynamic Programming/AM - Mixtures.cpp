#include <bits/stdc++.h>
using namespace std;

const int N = 105, mod = 100, inf = 2e9;
int n, a[N];
int dp[N][N];

int fun(int i, int j) {
  if (i == j) return 0;
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  int total = 0;
  for (int k = i; k <= j; k++) {
    total += a[k];
  }
  int sum = 0; ans = inf;
  for (int k = i; k < j; k++) {
    sum += a[k];
    int another = total - sum;
    int x = (sum % mod) * (another % mod) + (fun(i, k) + fun(k + 1, j));
    ans = min(ans, x);
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> n) {
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << fun(1, n) << '\n';
  }

  return 0;
}