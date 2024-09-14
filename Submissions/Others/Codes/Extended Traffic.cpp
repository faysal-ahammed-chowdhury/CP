#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 205, inf = 1e9;
vector<array<int, 2>> g[N];
int n, m, dis[N];

void bellman_ford(int src) {
  dis[src] = 0;
  for (int i = 1; i <= n; i++) {
    for (int u = 1; u <= n; u++) {
      for (auto [v, w] : g[u]) {
        if (dis[v] > dis[u] + w and dis[u] != inf) {
          dis[v] = dis[u] + w;
        }
      }
    }
  }
}


int cs;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    dis[i] = inf;
  }

  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    if (u == v) continue;
    int w = 1ll * (a[v] - a[u]) * (a[v] - a[u]) * (a[v] - a[u]);
    g[u].push_back({v, w});
  }
  
  bellman_ford(1);
  cout << "Case " << ++cs << ":\n";
  int q; cin >> q;
  while (q--) {
    int v; cin >> v;
    int d = dis[v];
    if (d < 3 or d >= inf) cout << "?\n";
    else cout << d << '\n';
  }
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