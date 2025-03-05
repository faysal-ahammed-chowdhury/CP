#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
int n, st, en;
vector<int> ans;

void clr(int n) {
  ans.clear();
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
}

void dfs(int u, int p) {
  for (auto v : g[u]) {
    if (v != p) dfs(v, u);
  }
  ans.push_back(u);
}

void solve() {
  cin >> n >> st >> en;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(en, 0);
  for (auto x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
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