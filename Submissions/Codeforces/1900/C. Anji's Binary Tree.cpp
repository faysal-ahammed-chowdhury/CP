#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9, inf = 2e9;
vector<pair<int, int>> g[N];
string s;

int dfs(int u) {
  int ans = inf;
  bool leaf = true;
  for (auto [v, w] : g[u]) {
    ans = min(ans, w + dfs(v));
    leaf = false;
  }
  ans = (leaf ? 0 : ans);
  return ans;
}

void solve() {
  int n; cin >> n;
  cin >> s;
  s = 'x' + s;
  for (int u = 1; u <= n; u++) {
    int l, r; cin >> l >> r;
    if (l) {
      g[u].push_back({l, s[u] != 'L'});
    }
    if (r) {
      g[u].push_back({r, s[u] != 'R'});
    }
  }
  cout << dfs(1) << '\n';

  for (int u = 1; u <= n; u++) {
    g[u].clear();
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}