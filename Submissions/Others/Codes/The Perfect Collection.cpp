#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 105, inf = 1e5;
int n;
int a[N];
int dp[N][N][1030];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = n + 1; i >= 1; i--) {
    for (int rem = 0; rem <= n; rem++) {
      for (int cur_xor = 0; cur_xor <= 1024; cur_xor++) {
        if (i == n + 1) {
          dp[i][rem][cur_xor] = rem == 0 ? cur_xor : inf;
        }
        else {
          dp[i][rem][cur_xor] = dp[i + 1][rem][cur_xor];
          if (rem > 0) dp[i][rem][cur_xor] = min(dp[i][rem][cur_xor], dp[i + 1][rem  - 1][cur_xor ^ a[i]]);
        }
      }
    }
  }

  while (q--) {
    int k; cin >> k;
    cout << dp[1][k][0];
    if (q) cout << '\n';
  }

  return 0;
}