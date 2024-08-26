#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 9;
int n, m, max_mex, dp[N];
vector<int> g[N];

int get(int n) {
  return (n * (n + 1)) / 2;
}

int dfs(int u, int p) {
  if (dp[u] != -1) return dp[u];
  int ans = u;
  for (auto v : g[u]) {
    if (v != p) {
      ans = max(ans, dfs(v, u));
    }
  }
  return dp[u] = ans;
}

void solve() {
  for (int i = 0; i <= max_mex; i++) {
    g[i].clear();
  }
  cin >> n >> m;
  map<int, int> cnt;
  max_mex = 0;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    set<int> se;
    for (int j = 0; j <= x + 5; j++) {
      se.insert(j);
    }
    for (int j = 1; j <= x; j++) {
      int y; cin >> y;
      se.erase(y);
    }
    int val = *se.begin();
    se.erase(se.begin());
    g[val].push_back(*se.begin());
    cnt[val]++;
    max_mex = max(max_mex, *se.begin());
    mx = max(mx, val);
  }
  for (int i = 0; i <= max_mex; i++) {
    dp[i] = -1;
  }
  for (auto [x, c] : cnt) {
    if (c > 1) {
      mx = max(mx, dfs(x, -1));
    }
  }
  int ans = 0;
  for (int i = 0; i <= min(m, max_mex); i++) {
    ans += max(i, max(mx, dfs(i, -1)));
  }
  if (m > max_mex) {
    ans += get(m) - get(max_mex);
  }
  cout << ans << '\n';
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