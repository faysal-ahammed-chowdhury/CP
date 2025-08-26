#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
const ll inf = 1e18;
int n, a[N];
ll dp[N][3];

ll f(int i, int condition) {
  if (i > n) return 0;
  ll &ans = dp[i][condition];
  if (ans != -1) return ans;
  ans = a[i] + f(i + 1, 1);
  ll x = inf;
  if (condition == 1) x = max(0, (a[i] - (i - 1)));
  else if (condition == 2) x = max(0, (a[i] - 1));
  ans = min(ans, x + f(i + 1, 2));
  // cout << i << ' ' << condition << ' ' << ans << '\n';
  return ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = -1;
    dp[i][1] = -1;
    dp[i][2] = -1;
  }
  cout << f(1, 0) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}