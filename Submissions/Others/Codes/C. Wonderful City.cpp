#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005;
const ll  inf = 1e18;
int h[N][N], a[N], b[N];
int n;
ll dp[N][2];

ll f(int i, bool last, bool is_row_operation) {
  if (i > n) return 0;
  bool possible = true, must = false;
  for (int j = 1; j <= n; j++) {
    if (h[i - 1][j] + last == h[i][j] + 1) possible = false;
    if (h[i - 1][j] + last == h[i][j]) must = true;
  }
  ll &ans = dp[i][last];
  if (ans != -1) return ans;
  ans = inf;
  int cost = is_row_operation ? a[i] : b[i];
  if (possible and must) {
    ans = cost + f(i + 1, true, is_row_operation);
    return ans;
  }
  if (possible and !must) {
    ans = min(f(i + 1, false, is_row_operation), cost + f(i + 1, true, is_row_operation));
    return ans;
  }
  if (!possible and must) {
    ans = inf;
    return inf;
  }
  ans = f(i + 1, false, is_row_operation);
  return ans;
}

void transpose() {
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      swap(h[i][j], h[j][i]);
    }
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    h[i][0] = -100;
    h[0][i] = -100;
    for (int j = 1; j <= n; j++) {
      cin >> h[i][j];
    }
  }
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = -1;
  ll ans = f(1, false, true);
  for (int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = -1;
  transpose();
  ans += f(1, false, false);
  cout << (ans >= inf ? -1 : ans) << '\n';
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