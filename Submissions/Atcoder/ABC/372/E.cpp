#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> par, sz;
  map<int, set<int, greater<int>>> childs;
  int c;
  DSU(int n) {
    par.resize(n + 1), sz.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) {
      par[i] = i;
      childs[i].insert(i);
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
    for (auto v : childs[j]) {
      childs[i].insert(v);
      if (childs[i].size() > 10) {
        childs[i].erase(--childs[i].end());
      }
    }
    childs[j].clear();
    par[j] = i;
    sz[i] += sz[j];

    // cout << "Here: ";
    // for (auto x : childs[i]) {
    //   cout << x << ' ';
    // }
    // cout << '\n';

    return i;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  DSU dsu(n);
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int u, v; cin >> u >> v;
      dsu.merge(u, v);
    }
    else {

      int v, k; cin >> v >> k;
      set<int, greater<int>> se = dsu.childs[dsu.find(v)];
      if (se.size() >= k) {
        int it = 1;
        for (auto u : se) {
          if (k == it) {
            cout << u << '\n';
            break;
          }
          it++;
        }
      }
      else cout << -1 << '\n';
    }
  }

  return 0;
}
