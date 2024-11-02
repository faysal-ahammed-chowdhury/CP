#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
const ll inf = 1e15; 
vector<array<int, 2>> g[N];
int n, m, par[N];

void dijkstra(int s) {
  vector<ll> dis(n + 1, inf);
  vector<bool> vis(n + 1, false);
  dis[s] = 0;
  priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
  pq.push({0, s});
  par[s] = s;
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (auto [v, w] : g[u]) {
      if (dis[v] > d + w) {
        dis[v] = d + w;
        pq.push({dis[v], v});
        par[v] = u;
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
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  memset(par, -1, sizeof par);
  dijkstra(1);

  if (par[n] == -1) {
    cout << -1 << '\n';
    return 0;
  }

  int cur = n;
  stack<int> st;
  while (par[cur] != cur) {
    st.push(cur);
    cur = par[cur];
  }
  st.push(1);
  while (!st.empty()) {
    cout << st.top() << ' ';
    st.pop();
  }
  cout << '\n';

  return 0;
}