#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g1[N], g2[N], g3[N];
int n, m1, m2, vis[N];

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

set<int> se;

void dfs(int u) {
  vis[u] = true;
  se.insert(u);
  for (auto v : g2[u]) {
    if (!vis[v]) dfs(v);
  }
}

void solve() {
  cin >> n >> m1 >> m2;

  for (int i = 1; i <= n; i++) {
    vis[i] = false;
    g1[i].clear();
    g2[i].clear();
    g3[i].clear();
  }

  while (m1--) {
    int u, v; cin >> u >> v;
    g1[u].push_back(v);
    g1[v].push_back(u);
  }
  while (m2--) {
    int u, v; cin >> u >> v;
    g2[u].push_back(v);
    g2[v].push_back(u);
  }

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      se.clear();
      dfs(i);
     
      for (auto x : se) {
        for (auto v : g1[x]) {
          if (se.find(v) == se.end()) {
            ans++;
          } 
          else {
            g3[x].push_back(v);
            g3[v].push_back(x);
          }
        }
      }
    }
  }

  ans /= 2;

  DSU dsu(n);
  for (int i = 1; i <= n; i++) {
    for (auto x : g3[i]) {
      dsu.merge(i, x);
    }
  }

  for (int i = 1; i <= n; i++) {
    vis[i] = false;
  }

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      se.clear();
      dfs(i);
     
      set<int> par;
      for (auto x : se) {
        par.insert(dsu.find(x));
      }

      ans += par.size() - 1;

      int last = -1;
      for (auto x : par) {
        if (last != -1) {
          dsu.merge(x, last);
        }
        last = x;
      }
    }
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