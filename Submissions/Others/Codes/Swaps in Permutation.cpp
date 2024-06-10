#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
int n, m, a[N];
vector<int> g[N], indices;
vector<bool> vis(N, false);

void dfs(int u) {
  vis[u] = true;
  indices.push_back(u);
  for (auto v : g[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int u = 1; u <= n; u++) {
    if (!vis[u]) {
      indices.clear();
      dfs(u);
      sort(indices.begin(), indices.end());
      vector<int> values;
      for (auto i : indices) {
        values.push_back(a[i]);
      }
      sort(values.begin(), values.end());
      for (auto i : indices) {
        a[i] = values.back();
        values.pop_back();
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';

  return 0;
}