#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
vector<int> g[N];
vector<bool> vis(N, false);
vector<int> dis(N, 0);

void bfs(int u) {
  queue<int> q;
  q.push(u);
  vis[u] = true;
  dis[u] = 0;

  while(!q.empty()) {
    int top = q.front();
    q.pop();

    for(auto v: g[top]) {
      if(!vis[v]) {
        q.push(v);
        vis[v] = true;
        dis[v] = dis[top] + 1;
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for(int u = 1; u <= n; u++) {
    int v; cin >> v;
    a[u] = v;
    if(v == -1) continue;
    g[v].push_back(u);
  }

  for(int i = 1; i <= n; i++) {
    if(a[i] == -1) {
      bfs(i);
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans = max(ans, dis[i]);
  }
  cout << ans + 1 << '\n';

  return 0;
}