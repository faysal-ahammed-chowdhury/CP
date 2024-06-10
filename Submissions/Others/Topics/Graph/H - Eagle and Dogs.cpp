#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 9;
vector<pair<int, int>> g[N];
int n;

int bfs(int u, vector<ll> &dis) {
  dis.resize(n + 2);
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

  int farthest = max_element(dis.begin() + 1, dis.end()) - dis.begin();
  return farthest;
}

void solve() {
  cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  vector<ll> dis1(n + 2), dis2(n + 2);
  int s = bfs(1, dis1);
  int e = bfs(s, dis1);
  bfs(e, dis2);

  for(int i = 1; i <= n; i++) {
    cout << max(dis1[i], dis2[i]) << ' ';
  }
  cout << '\n';

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