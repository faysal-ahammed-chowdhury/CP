#include <bits/stdc++.h>
using namespace std;

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
  int n; cin >> n;
  vector<array<int, 3>> edges;
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x; cin >> x;
      if (x) edges.push_back({x, i, j});
      tot += x;
    }
  }
  sort(edges.begin(), edges.end());
  DSU dsu(n);
  int min_cost = 0;
  for (auto [w, u, v] : edges) {
    if (!dsu.same(u, v)) {
      dsu.merge(u, v);
      min_cost += w;
    }
  }
  cout << "Case " << ++cs << ": " << (dsu.count() == 1 ? tot - min_cost : -1) << '\n';
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