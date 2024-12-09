#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, MAX = 1e6 + 9, mod = 1e9 + 7;
int n, a[N], dp[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vector<int> divs;
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        divs.push_back(j);
        if (j != (a[i] / j)) divs.push_back(a[i] / j);
      }
    }
    sort(divs.rbegin(), divs.rend());

    for (auto x : divs) {
      if (x > n) continue;
      dp[x] = (dp[x] + dp[x - 1]) % mod;
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += dp[i];
    ans %= mod;
  }
  cout << ans << '\n';

  return 0;
}