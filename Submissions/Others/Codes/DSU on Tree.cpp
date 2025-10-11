#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
vector<int> g[N];
set<int> se[N];
int col[N], ans[N], par[N];

int find(int i) {
  return (i == par[i] ? i : par[i] = find(par[i]));
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return;
  if (se[u].size() > se[v].size()) swap(u, v);
  for (auto x : se[u]) {
    se[v].insert(x);
  }
  se[u].clear();
  par[u] = v;
}

void dfs(int u, int p) {
  se[find(u)].insert(col[u]);
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      merge(u, v);
    }
  }
  ans[u] = se[find(u)].size();
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> col[i];
    par[i] = i;
  }

  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}
// https://cses.fi/problemset/task/1139