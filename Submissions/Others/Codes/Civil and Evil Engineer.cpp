#include <bits/stdc++.h>
using namespace std;

const int N = 105;
vector<array<int, 3>> edges1, edges2;
int n;

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
  edges1.clear(), edges2.clear();
  cin >> n;
  ++n;
  int u, v, w;
  while (cin >> u >> v >> w) {
    if (u == 0 and v == 0 and w == 0) break;
    ++u, ++v;
    edges1.push_back({w, u, v});
    edges2.push_back({-w, u, v});
  }
  sort(edges1.begin(), edges1.end());
  sort(edges2.begin(), edges2.end());
  DSU dsu1(n), dsu2(n);
  int min_cost = 0, max_cost = 0;
  for (auto [w, u, v] : edges1) {
    if (!dsu1.same(u, v)) {
      dsu1.merge(u, v);
      min_cost += w;
    }
  }
  for (auto [w, u, v] : edges2) {
    if (!dsu2.same(u, v)) {
      dsu2.merge(u, v);
      max_cost += -w;
    }
  }
  int total_cost = min_cost + max_cost;
  cout << "Case " << ++cs << ": ";
  (total_cost % 2 == 0 ? cout <<  total_cost / 2 << '\n' : cout << total_cost << '/' << 2 << '\n');
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