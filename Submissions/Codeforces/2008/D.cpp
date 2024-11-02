#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N];
vector<bool> vis(N, false);
int ans[N], par[N], cnt;
string s;

void dfs(int u, int p) {
  if (s[u] == '0') cnt++;
  par[u] = p;
  vis[u] = true;
  for (auto v : g[u]) {
    if (!vis[v]) {
      dfs(v, p);
    }
  }
}

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    ans[i] = 0;
    par[i] = 0;
    vis[i] = false;
  }
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    g[i].push_back(x);
  }
  cin >> s;
  s = '.' + s;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) {
      cout << ans[par[i]] << ' ';
    }
    else {
      cnt = 0;
      dfs(i, i);
      ans[i] = cnt;
      cout << ans[i] << ' ';
    }
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}