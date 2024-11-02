#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<array<int, 2>> g[N];
vector<int> dis(N, 0), nodes, ans;
vector<bool> vis(N, false);
int n, m;

void bellman_ford(int s) {
  dis[s] = 0;
  for (int i = 1; i <= n; i++) {
    for (int u = 1; u <= n; u++) {
      for (auto [v, w] : g[u]) {
        if (dis[v] > dis[u] + w) {
          if (i == n) {
            nodes.push_back(v);
          }
          dis[v] = dis[u] + w;
        }
      }
    }
  }
}

void dfs(int u) {
  ans.push_back(u);
  vis[u] = true;
  for (auto [v, w] : g[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

int cs;
void solve() {
  cin >> n >> m;

  ans.clear();
  nodes.clear();
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    dis[i] = 0;
    vis[i] = false;
  }

  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    ++u, ++v;
    g[v].push_back({u, w});
  }
  bellman_ford(0);

  cout << "Case " << ++cs << ": ";
  if (nodes.empty()) {
    cout << "impossible\n";
    return;
  }

  for (auto u : nodes) {
    if (!vis[u]) {
      dfs(u);
    }
  }
  sort(ans.begin(), ans.end());
  for (auto x : ans) {
    cout << --x << ' ';
  }
  cout << '\n';
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