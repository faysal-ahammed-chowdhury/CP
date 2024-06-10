#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int n, a[N], b[N], c[N], dp[N][5];

int fun(int i, int last) {
  if(i == 0) return 0;
  int &ans = dp[i][last];
  if(ans != -1) return ans;
  if(last == 0) {
    ans = max(ans, b[i] + fun(i - 1, 1));
    ans = max(ans, c[i] + fun(i - 1, 2));
  }
  else if(last == 1) {
    ans = max(ans, a[i] + fun(i - 1, 0));
    ans = max(ans, c[i] + fun(i - 1, 2));
  }
  else {
    ans = max(ans, a[i] + fun(i - 1, 0));
    ans = max(ans, b[i] + fun(i - 1, 1));
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }

  cout << max(max(fun(n, 0), fun(n, 1)), fun(n, 2)) << '\n';

  return 0;
}