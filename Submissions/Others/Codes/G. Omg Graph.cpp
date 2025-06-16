#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9, inf = 1e16;
vector<pair<int, int>> g[N];
int n, m;
pair<int, int> min_max1[N], min_max2[N];

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
}

struct DSU {
  vector<int> par, sz;
  int c;
  DSU(int n) {
    par.resize(n + 1), sz.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) {
      par[i] = i;
    }
    c = n;
  }
  int find(int i) {
    return (i == par[i] ? i : par[i] = find(par[i]));
  }
  bool same(int i, int j) {
    return find(i) == find(j);
  }
  int get_size(int i) {
    return sz[find(i)];
  }
  int count() { // number of connected components
    return c;
  }
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return -1;
    c--;
    if (sz[i] < sz[j]) swap(i, j);
    par[j] = i;
    sz[i] += sz[j];
    return i;
  }
};

void dfs1(int u, int p, int mn, int mx) {
  min_max1[u] = {mn, mx};
  for (auto [v, w] : g[u]) {
    if (v != p) {
      dfs1(v, u, min(mn, w), max(mx, w));      
    }
  }
}

void dfs2(int u, int p, int mn, int mx) {
  min_max2[u] = {mn, mx};
  for (auto [v, w] : g[u]) {
    if (v != p) {
      dfs2(v, u, min(mn, w), max(mx, w));      
    }
  }
}

void solve() {
  cin >> n >> m;
  clr(n);
  vector<array<int, 3>> edges;
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    edges.push_back({w, u, v});
  }

  sort(edges.begin(), edges.end());
  DSU dsu(n);
  for (auto [w, u, v] : edges) {
    if (!dsu.same(u, v)) {
      g[u].push_back({v, w});
      g[v].push_back({u, w});
      dsu.merge(u, v);
    }
  }

  dfs1(1, 0, inf, -inf);
  dfs2(n, 0, inf, -inf);
  int ans = inf;
  for (int i = 2; i <= n; i++) {
    // cout << i << ' ' << min_max[i].first + min_max[i].second << '\n';
    int mn = min(min_max1[i].first, min_max2[i].first);
    int mx = max(min_max1[i].second, min_max2[i].second);
    ans = min(ans, mn + mx);
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