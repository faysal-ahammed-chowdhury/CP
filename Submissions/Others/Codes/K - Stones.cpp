#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 105, K = 1e5 + 9;
int n, k, a[N];
bool dp[K][2];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int rem = 0; rem <= k; rem++) {
    for (int who = 0; who <= 1; who++) {
      if (who == 0) {
        bool ans = false;
        for (int i = 1; i <= n; i++) {
          if (rem >= a[i]) ans |= dp[rem - a[i]][who ^ 1];
        }
        dp[rem][who] = ans;
      }
      else {
        bool ans = true;
        for (int i = 1; i <= n; i++) {
          if (rem >= a[i]) ans &= dp[rem - a[i]][who ^ 1];
        }
        dp[rem][who] = ans;
      }
    }
  }

  cout << (dp[k][0] ? "First" : "Second") << '\n';

  return 0;
}