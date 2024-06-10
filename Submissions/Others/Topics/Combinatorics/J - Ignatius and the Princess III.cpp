#include <bits/stdc++.h>
using namespace std;

const int N = 122;
int n, dp[N][N];

int fun(int last, int sum) {
  if (sum == n) return 1;
  int &ans = dp[last][sum];
  if (ans != -1) return ans;
  ans = 0;
  for (int i = last; i <= n; i++) {
    if (sum + i <= n) {
      ans += fun(i, sum + i);
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> n) {
    memset(dp, -1, sizeof(dp));
    cout << fun(1, 0) << '\n';
  }

  return 0;
}