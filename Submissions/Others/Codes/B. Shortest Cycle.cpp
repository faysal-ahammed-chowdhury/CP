#include <bits/stdc++.h>
using namespace std;
#define int long long

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }

const int N = 125, inf = 1e9;
int n, cnt[65];
vector<int> g[N];
vector<int> a;

auto bfs(int u) {
  queue<int> q;
  vector<int> dis(n + 1, inf);
  vector<bool> vis(n + 1, false);
  q.push(u);
  vis[u] = true;
  dis[u] = 0;
  while (!q.empty()) {
    int top = q.front(); q.pop();
    for (auto v : g[top]) {
      if (!vis[v]) {
        q.push(v);
        dis[v] = dis[top] + 1;
        vis[v] = true;
      }
    }
  }
  return dis;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x == 0) continue;
    a.push_back(x);
  }
  n = a.size();

  for (int k = 0; k < 60; k++) {
    for (int i = 0; i < n; i++) {
      if (CHECK(a[i], k)) cnt[k]++;
    }
    if (cnt[k] >= 3) {
      cout << 3 << '\n';
      return 0;
    }
  }

  vector<pair<int, int>> edges;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] & a[j]) {
        edges.push_back({i + 1, j + 1});
      }
    }
  }

  int ans = inf;

  for (int i = 0; i < edges.size(); i++) {
    for (int u = 1; u <= n; u++) {
      g[u].clear();
    }
    for (int j = 0; j < edges.size(); j++) {
      if (i == j) continue;
      g[edges[j].first].push_back(edges[j].second);
      g[edges[j].second].push_back(edges[j].first);
    }
    auto dis = bfs(edges[i].first);
    ans = min(ans, dis[edges[i].second] + 1);
  }
  cout << (ans >= inf ? -1 : ans) << '\n';


  return 0;
}