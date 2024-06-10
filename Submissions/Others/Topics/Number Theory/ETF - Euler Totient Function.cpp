#include <bits/stdc++.h>
using namespace std;

// if we need phi(x) multiple times, then memoize it
map<int, int> dp;
int phi(int n) {
  if (dp.count(n)) return dp[n];
  int ans = n, m = n;
  for (int i = 2; i * i <= m; i++) {
    if (m % i == 0) {
      while (m % i == 0) m /= i;
      ans = ans / i * (i - 1);
    }
  }
  if (m > 1) ans = ans / m * (m - 1);
  return dp[n] = ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  return 0;
}