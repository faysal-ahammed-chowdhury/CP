#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005, X = 1e5 + 9;
int n, x, price[N], page[N], dp[N][X];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> price[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> page[i];
  }

  for (int i = n; i >= 1; i--) {
    for (int taka = 0; taka <= x; taka++) {
      int &ans = dp[i][taka];
      ans = max(dp[i + 1][taka], taka >= 1 ? dp[i][taka - 1] : 0);
      if (taka >= price[i]) {
        ans = max(ans, page[i] + dp[i + 1][taka - price[i]]);
      }
    }
  }

  cout << dp[1][x] << '\n';

  return 0;
}