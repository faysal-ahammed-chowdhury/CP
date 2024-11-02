#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 10005;
const ll inf = 1e18;
int n, d, health[N], damage[N];
ll dp[N][2];

ll f(int i, bool last) {
  if (i > n) return (last ? 0 : inf);
  ll &ans = dp[i][last];
  if (ans != -1) return ans;
  ans = inf;
  if (last) {
    int h = health[i] - damage[i - 1];
    h = max(0, h);
    ll cost = (h + d - 1) / d;
    ans = min(ans, cost + f(i + 1, true));
    h = health[i] - damage[i - 1] - damage[i + 1];
    h = max(0, h);
    cost = (h + d - 1) / d;
    ans = min(ans, cost + f(i + 1, false));
  }
  else {
    int h = health[i];
    ll cost = (h + d - 1) / d;
    ans = min(ans, cost + f(i + 1, true));
    h = health[i] - damage[i + 1];
    h = max(0, h);
    cost = (h + d - 1) / d;
    ans = min(ans, cost + f(i + 1, false));
  }
  return ans;
}

void solve() {
  cin >> n >> d;
  memset(dp, -1, sizeof dp);
  memset(health, 0, sizeof health);
  memset(damage, 0, sizeof damage);
  for (int i = 1; i <= n; i++) {
    cin >> health[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> damage[i];
  }
  cout << f(1, false) << '\n';
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