#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e5 + 9;
int n, a[N];
long long dp[N]; 


long long func(int pos) {
  if(pos > n) {
    return 0;
  }

  if(dp[pos] != -1) {
    return dp[pos];
  }

  long long ans1 = a[pos] + func(pos + 2);
  long long ans2 = func(pos + 1);
  long long ans = max(ans1, ans2);
  dp[pos] = ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  cout << func(1) << '\n';

  return 0;
}