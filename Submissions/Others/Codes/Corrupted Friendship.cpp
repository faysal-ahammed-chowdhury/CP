#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 9;
vector<int> g[N], child(N);
int n, ans;

void dfs(int u, int p) {
  child[u] = 1;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      ans += (child[u] - 1) * child[v];
      child[u] += child[v];
    }
  }
}

int cs;
void solve() {
  cin >> n;
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    child[i] = 0;
  }
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ans = 0;
  dfs(1, -1);
  cout << "Case " << ++cs << ": " << n - 1 << ' ' << ans << '\n';
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