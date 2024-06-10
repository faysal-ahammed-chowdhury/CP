#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, inf = 2e9;
int n, dp[N];

int fun(int i) {
  if(i == 0) return 0;
  if(dp[i] != -1) return dp[i];
  int ans = inf;
  int x = i;
  while(x > 0) {
    int last = x % 10;
    x /= 10;
    if(last != 0) {
      ans = min(ans, 1 + fun(i - last));
    }
  }
  return dp[i] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);

  cin >> n;
  cout << fun(n) << '\n';

  return 0;
}