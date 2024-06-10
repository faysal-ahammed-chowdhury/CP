#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const double eps = 1e-6;
const int N = 1e3 + 9;
int a[N];
vector<int> g[N];
vector<bool> vis(N, false);
int sum, cnt;

void dfs(int u) {
  sum += a[u];
  cnt++;
  vis[u] = true;
  for (auto v: g[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

void solve() {
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    g[i].clear();
    vis[i] = false;
  }
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while(m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int avg = -1;
  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      sum = 0;
      cnt = 0;
      dfs(i);
      if(sum % cnt != 0) {
        cout << "No\n";
        return;
      }
      else if(avg == -1) {
        avg = sum / cnt;
      }
      else if(avg != (sum / cnt)) {
        cout << "No\n";
        return;
      }
    }
  }
  cout << "Yes\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0; cin >> t;
  while(t--) {
    cout << "Case " << ++cs << ": ";
    solve();
  }

  return 0;
}