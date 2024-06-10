#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, inf = 2e9;
vector<int> g[N];
vector<bool> vis(N, false);
vector<int> a(N);

int bfs(int u) {
  queue<int> q;
  q.push(u);
  vis[u] = true;
  int ans = inf;

  while(!q.empty()) {
    int top = q.front();
    q.pop();

    ans = min(ans, a[top]);

    for(auto v: g[top]) {
      if(!vis[v]) {
        q.push(v);
        vis[v] = true;
      }
    }
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while(m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  long long ans = 0;
  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      ans += bfs(i);
    }
  }
  cout << ans << '\n';

  return 0;
}