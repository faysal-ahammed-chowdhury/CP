#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> par, sz;
  int c, mx_component_sz = 1;;
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
  int get_max_component_size() {
    return mx_component_sz;
  }
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return -1;
    c--;
    if (sz[i] < sz[j]) swap(i, j);
    par[j] = i;
    sz[i] += sz[j];
    mx_component_sz = max(mx_component_sz, sz[i]);
    return i;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  DSU dsu(n);
  while (m--) {
    int u, v; cin >> u >> v;
    dsu.merge(u, v);
    cout << dsu.count() << ' ' << dsu.get_max_component_size() << '\n';
  }

  return 0;
}
// https://cses.fi/problemset/task/1676