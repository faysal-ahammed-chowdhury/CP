#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }
void CLEAR(int &N, int pos) { (N &= ~(1 << pos)); }

const int N = 14;
int n, a[N][N], dp[(1 << N) + 5], cost[(1 << N) + 5];
bool vis[(1 << N) + 5];

int get_cost(int mask) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (CHECK(mask, i) == false) continue;
    for (int j = i + 1; j < n; j++) {
      if (CHECK(mask, j) == false) continue;
      ans += a[i][j];
      ans += a[j][i];
    }
  }
  return ans;
}

int f(int mask) {
  if (vis[mask]) return dp[mask];
  vis[mask] = true;
  int ans = 0;
  for (int submask = mask; submask; submask = (submask - 1) & mask) {
    ans = min(ans, cost[submask] + f(mask ^ submask));
  }
  return dp[mask] = ans;
}

int cs;
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int mask = 0; mask <= (1 << n); mask++) {
    cost[mask] = get_cost(mask);
  }
  memset(vis, false, sizeof vis);
  cout << "Case " << ++cs << ": " << f((1 << n) - 1) << '\n';
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