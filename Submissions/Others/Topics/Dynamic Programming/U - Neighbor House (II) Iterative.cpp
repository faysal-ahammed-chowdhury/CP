#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N], dp[N][2][2];

int cs = 0;
void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = n + 1; i >= 1; i--) {
    for (int last = 0; last < 2; last++) {
      for (int first = 0; first < 2; first++) {
        if (i == n + 1) {
          dp[i][last][first] = 0;
        }
        else if (i == n) {
          if (last == 0 and first == 0) {
            dp[i][last][first] = a[i];
          }
          else {
            dp[i][last][first] = 0;
          }
        }
        else {
          int &ans = dp[i][last][first];
          ans = dp[i + 1][0][first];
          if (last == 0) {
            ans = max(ans, a[i] + dp[i + 1][1][first]);
          }
        }
      }
    }
  }

  cout << "Case " << ++cs << ": " << max(dp[2][0][0], a[1] + dp[2][1][1]) << '\n';
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