#include <bits/stdc++.h>
using namespace std;

const int N = 105, inf = 1e9;
vector<int> g[N];

void bfs(int u, vector<bool> &vis, vector<int> &dis) {
  vis[u] = true;
  dis[u] = 0;
  queue<int> q;
  q.push(u);
  while(!q.empty()) {
    int top = q.front(); q.pop();
    for(auto v: g[top]) {
      if(!vis[v]) {
        vis[v] = true;
        q.push(v);
        dis[v] = dis[top] + 1;
      }
    }
  }
}

int cs = 0;
void solve() {
  cout << "Case " << ++cs << ": ";
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    g[i].clear();
  }
  while(m--) {
    int u, v; cin >> u >> v;
    u++, v++;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int a, b; cin >> a >> b;
  a++, b++;
  vector<bool> vis1(N, false);
  vector<int> dis1(N, inf);
  bfs(a, vis1, dis1);

  vector<bool> vis2(N, false);
  vector<int> dis2(N, inf);
  bfs(b, vis2, dis2);

  int ans = -inf;
  for(int i = 1; i <= n; i++) {
    ans = max(ans, dis1[i] + dis2[i]);
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}