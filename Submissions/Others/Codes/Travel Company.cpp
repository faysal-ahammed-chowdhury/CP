#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 105;
const ll inf = 1e18;
vector<pair<int, ll>> g[N];
vector<ll> dis(N, inf);
int n, m, p;

bool bellman_ford(int s) {
  dis[s] = 0;
  bool has_cycle = false;
  for (int i = 1; i <= n; i++) {
    for (int u = 1; u <= n; u++) {
      for (auto [v, w] : g[u]) {
        if (dis[v] > dis[u] + w) {
          if (i == n) has_cycle = true;
          dis[v] = dis[u] + w;
        }
      }
    }
  }
  return has_cycle;
}

int cs;
void solve() {
  cin >> n >> m >> p;

  for (int i = 1; i <= n; i++) {
    g[i].clear();
    dis[i] = inf;
  }

  while (m--) {
    int u, v, in, ex; cin >> u >> v >> in >> ex;
    ll w = 1ll * p * ex - in;
    ++u, ++v;
    g[u].push_back({v, w});
  }

  bool has_cycle = bellman_ford(1);
  cout << "Case " << ++cs << ": ";
  if (has_cycle) cout << "YES\n";
  else cout << "NO\n";
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