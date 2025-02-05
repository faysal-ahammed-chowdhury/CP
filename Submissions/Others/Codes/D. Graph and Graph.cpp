#include <bits/stdc++.h>
using namespace std;

const int N = 1005, inf = 2e9;
vector<int> g1[N], g2[N];
int dis[N][N];
bool vis[N][N];
set<pair<int, int>> e1, e2;

void clr(int n) {
  e1.clear();
  e2.clear();
  for (int i = 0; i <= n; i++) {
    g1[i].clear();
    g2[i].clear();
    for (int j = 0; j <= n; j++) {
      vis[i][j] = false;
      dis[i][j] = inf;
    }
  }
}

void dijkstra(int s1, int s2) {
  dis[s1][s2] = 0;
  priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
  pq.push({0, s1, s2});
  while (!pq.empty()) {
    auto [d, u1, u2] = pq.top(); pq.pop();
    if (vis[u1][u2]) continue;
    vis[u1][u2] = true;
    for (auto v1 : g1[u1]) {
      for (auto v2 : g2[u2]) {
        int cost = abs(v1 - v2);
        if (dis[v1][v2] > d + cost) {
          dis[v1][v2] = d + cost;
          pq.push({dis[v1][v2], v1, v2});
        }
      }
    }
  }
}

void solve() {
  int n, s1, s2; cin >> n >> s1 >> s2;
  clr(n);
  int m1; cin >> m1;
  while (m1--) {
    int u, v; cin >> u >> v;
    g1[u].push_back(v);
    g1[v].push_back(u);
    if (u > v) swap(u, v);
    e1.insert({u, v});
  }
  int m2; cin >> m2;
  while (m2--) {
    int u, v; cin >> u >> v;
    g2[u].push_back(v);
    g2[v].push_back(u);
    if (u > v) swap(u, v);
    e2.insert({u, v});
  }

  dijkstra(s1, s2);

  int ans = inf;
  for (auto e : e1) {
    if (e2.find(e) != e2.end()) {
      ans = min(ans, dis[e.first][e.first]);
    }
  }

  cout << (ans >= inf ? -1 : ans) << '\n';
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