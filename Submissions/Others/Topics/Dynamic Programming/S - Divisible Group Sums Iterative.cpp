#include <bits/stdc++.h>
using namespace std;
const int N = 205, M = 15, D = 25;
using ll = long long;
int n, q, m, d, a[N];
ll dp[N][D][M];

int cs = 0;
void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cout << "Case " << ++cs << ":\n";
  while (q--) {
    cin >> d >> m;

    for (int i = n + 1; i >= 1; i--) {
      for (int sum = 0; sum <= d; sum++) {
        for (int taken = 0; taken <= m; taken++) {
          if (i == n + 1) {
            if (sum == 0 and taken == m) dp[i][sum][taken] = 1;
            else dp[i][sum][taken] = 0;
          }
          else {
            ll &ans = dp[i][sum][taken];
            ans = 0;
            if (taken + 1 <= m) {
              ans = dp[i + 1][(sum + ((a[i] % d) + d) % d) % d][taken + 1];
            }
            ans += dp[i + 1][sum][taken];
          }
        }
      }
    }
    
    cout << dp[1][0][0] << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}