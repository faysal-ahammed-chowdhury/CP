#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005; // change here
const ll inf = 1e18;
vector<array<int, 2>> g[N];
vector<ll> dis(N, inf);
int n, m;
bool cycle;

void bellman_ford(int s) {
  dis[s] = 0;
  for (int i = 1; i <= n; i++) {
    for (int u = 1; u <= n; u++) {
      for (auto [v, w] : g[u]) {
        if (dis[v] > dis[u] + w and dis[u] != inf) {
          if (i == n) cycle = true;
          dis[v] = dis[u] + w;
        }
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({ v,w });
    g[v].push_back({ u,w });
  }

  cycle = false;
  bellman_ford(1);

  for (int u = 1; u <= n; u++) {
    cout << dis[u] << ' ';
  }
  cout << '\n';


  return 0;
}