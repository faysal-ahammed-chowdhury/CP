#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> par, sz, cycle_cnt;
  int c;
  DSU(int n) {
    par.resize(n + 1), sz.resize(n + 1, 1);
    cycle_cnt.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) {
      par[i] = i;
      cycle_cnt[i] = 0;
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
    cycle_cnt[i] += cycle_cnt[j];
    cycle_cnt[j] = 0;
    sz[i] += sz[j];
    return i;
  }
};

void solve() {
  int n; cin >> n;

  vector<array<int, 2>> edges;
  map<array<int, 2>, int> mp;
  bool notok = false;
  for (int i = 1; i <= n; i++) {
    int u, v; cin >> u >> v;
    if (u > v) swap(u, v);
    edges.push_back({u, v});
    notok |= mp[ {u, v}] > 2;
  }

  if (notok) {
    cout << "impossible\n";
    return;
  }

  int m = n + n + 5;
  DSU dsu(m);
  for (auto [u, v] : edges) {
    if (!dsu.same(u, v)) {
      dsu.merge(u, v);
    }
    else {
      dsu.cycle_cnt[dsu.find(u)]++;
    }
  }

  for (int i = 1; i < m; i++) {
    if (dsu.cycle_cnt[dsu.find(i)] >= 2) {
      cout << "impossible\n";
      return;
    }
  }

  cout << "possible\n";
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