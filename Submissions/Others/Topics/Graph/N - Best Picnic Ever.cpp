#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> g[N];
vector<int> cnt(N, 0);

void bfs(int u, vector<bool> &vis) {
  queue<int> q;
  q.push(u);
  vis[u] = true;
  while(!q.empty()) {
    int top = q.front(); q.pop();
    cnt[top]++;
    for(auto v: g[top]) {
      if(!vis[v]) {
        q.push(v);
        vis[v] = true;
      }
    }
  }
}

int cs = 0;
void solve() {
  cout << "Case " << ++cs << ": ";
  int k, n, m; cin >> k >> n >> m;
  int a[k + 1];
  for(int i = 1; i <= k; i++) {
    cin >> a[i];
  }
  while(m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
  }

  for(int i = 1; i <= k; i++) {
    vector<bool> vis(N, false);
    bfs(a[i], vis);
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(cnt[i] == k) ans++;
  }
  cout << ans << '\n';

  for(int i = 1; i <= n; i++) {
    g[i].clear();
    cnt[i] = 0;
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