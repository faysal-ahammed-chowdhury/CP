#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, mod = 1e9 + 7;
int n, dp[N];

int fun(int i) {
  if(i == 0) return 1;
  if(dp[i] != -1) return dp[i];
  int ans = 0;
  for(int j = 1; j <= 6; j++) {
    if(j <= i) {
      ans += fun(i - j) % mod;
      ans %= mod;
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