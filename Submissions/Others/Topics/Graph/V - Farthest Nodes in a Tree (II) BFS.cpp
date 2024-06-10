#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 5;
vector<pair<int, int>> g[N];
int n; 

int bfs(int u, vector<int> &dis) {
  dis.resize(n + 1);
  for(int i = 1; i <= n; i++) {
    dis[i] = -1;
  }
  dis[u] = 0;
  queue<int> q;
  q.push(u);

  while(!q.empty()) {
    int top = q.front();
    q.pop();
    for(auto [v, w]: g[top]) {
      if(dis[v] == -1) {
        dis[v] = dis[top] + w;
        q.push(v);
      }
    }
  }

  int farthest = max_element(dis.begin() + 1, dis.end()) -  dis.begin();
  return farthest;
}

int cs = 0;
void solve() {
  cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v, w; cin >> u >> v >> w;
    u++, v++;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  vector<int> dis1(n + 5, -1), dis2(n + 5, -1);
  int s = bfs(1, dis1);
  int e = bfs(s, dis1);
  bfs(e, dis2);

  cout << "Case " << ++cs << ":\n";
  for(int i = 1; i <= n; i++) {
    cout << max(dis1[i], dis2[i]) << '\n';
  }

  for(int i = 1; i <= n; i++) {
    g[i].clear();
  }
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