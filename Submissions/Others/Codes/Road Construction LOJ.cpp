#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

int cs;
void solve() {
  int m; cin >> m;
  vector<pair<int, pair<string, string>>> tmp_edges;
  o_set<string> se;
  for (int i = 1; i <= m; i++) {
    string u, v; int w; cin >> u >> v >> w;
    tmp_edges.push_back(make_pair(w, make_pair(u, v)));
    se.insert(u);
    se.insert(v);
  }
  vector<array<int, 3>> edges;
  for (auto e : tmp_edges) {
    int u = se.order_of_key(e.second.first) + 1;
    int v = se.order_of_key(e.second.second) + 1;
    int w = e.first;
    edges.push_back({w, u, v});
  }
  int sz = se.size();
  sort(edges.begin(), edges.end());
  DSU dsu(sz);
  int ans = 0;
  for (auto e : edges) {
    int w = e[0], u = e[1], v = e[2];
    if (!dsu.same(u, v)) {
      dsu.merge(u, v);
      ans += w;
    }
  }
  cout << "Case " << ++cs << ": ";
  if (dsu.count() == 1) cout << ans << '\n';
  else cout << "Impossible\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
