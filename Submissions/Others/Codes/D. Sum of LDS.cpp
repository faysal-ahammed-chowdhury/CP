#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500000 + 9;
int n, a[N];
ll dp[N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[n] = 1;
  dp[n - 1] = 1 + (a[n - 1] > a[n] ? 2 : 1);
  for (int i = n - 2; i >= 1; i--) {
    if (a[i] > a[i + 1]) {
      dp[i] = dp[i + 1] + (n - i + 1);
    }
    else {
      dp[i] = dp[i + 1] + 1;
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += dp[i];
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}