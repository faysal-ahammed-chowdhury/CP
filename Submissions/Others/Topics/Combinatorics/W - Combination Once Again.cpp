#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const int N = 55;
int n, m, r, cnt[N];
bool vis[N][N];
ull dp[N][N];

ull fun(int i, int taken) {
  if (i == n + 1) {
    return taken == r;
  }

  if (vis[i][taken]) {
    return dp[i][taken];
  }

  vis[i][taken] = true;
  ull &ans = dp[i][taken];
  ans = 0;
  for (int k = 0; k <= cnt[i]; k++) {
    ans += fun(i + 1, taken + k);
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int cs = 0;
  while (cin >> n >> m and n and m) {
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) {
      int x; cin >> x;
      cnt[x]++;
    }

    cout << "Case " << ++cs << ":\n";
    while (m--) {
      cin >> r;
      memset(vis, 0, sizeof(vis));
      cout << fun(1, 0) << '\n';
    }
  }

  return 0;
}