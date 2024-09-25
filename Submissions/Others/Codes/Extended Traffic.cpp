#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 205;
const ll inf = 1e18;
vector<array<ll, 2>> g[N];
vector<ll> dis(N, inf), nodes;
vector<bool> vis(N, false), not_reachable(N, false);
int n, m, a[N];

void bellman_ford(int s) {
  dis[s] = 0;
  for (int i = 1; i <= n; i++) {
    for (int u = 1; u <= n; u++) {
      for (auto [v, w] : g[u]) {
        if (dis[v] > dis[u] + w and dis[u] != inf) {
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
  not_reachable[u] = true;
  vis[u] = true;
  for (auto [v, w] : g[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

int cs;
void solve() {
  cin >> n;

  nodes.clear();
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    dis[i] = inf;
    vis[i] = false;
    not_reachable[i] = false;
  }

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  cin >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    ll w = 1ll * (a[v] - a[u]) * (a[v] - a[u]) * (a[v] - a[u]);
    g[u].push_back({ v, w });
  }

  bellman_ford(1);

  for (auto u : nodes) {
    if (!vis[u]) {
      dfs(u);
    }
  }

  int q; cin >> q;
  cout << "Case " << ++cs << ":\n";
  while (q--) {
    int v; cin >> v;
    if (not_reachable[v] or dis[v] < 3 or dis[v] >= inf) cout << "?\n";
    else cout << dis[v] << '\n';
  }
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