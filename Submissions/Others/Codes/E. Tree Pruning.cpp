#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 5e5 + 9;
vector<int> g[N];
int level[N], depth[N];

void dfs(int u, int p) {
  level[u] = level[p] + 1;
  depth[u] = level[u];
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      depth[u] = max(depth[u], depth[v]);
    }
  }
}

void solve() {
  int n; cin >> n;

  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }

  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  level[0] = -1;
  dfs(1, 0);
  o_set<array<int, 2>> se1, se2;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    mx = max(mx, level[i]);
    se1.insert({level[i], i});
    se2.insert({depth[i], i});
  }

  int ans = 1e9;
  for (int lvl = 0; lvl <= mx; lvl++) {
    int here = n - se1.order_of_key({lvl + 1, 0});
    here += se2.order_of_key({lvl, 0});
    ans = min(ans, here);
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