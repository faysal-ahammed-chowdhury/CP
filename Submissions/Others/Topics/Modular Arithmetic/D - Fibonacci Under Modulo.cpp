#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int N = 1e5 + 9;
int dp[N];

int fibo(int n) {
  if(n == 1 || n == 2) {
    return 1;
  }
  if(dp[n] != -1) {
    return dp[n];
  }
  int ans = (fibo(n - 1) % mod + fibo(n - 2) % mod) % mod;
  dp[n] = ans;
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));
  int n; cin >> n;
  cout << fibo(n) << '\n';
        
  return 0;
}