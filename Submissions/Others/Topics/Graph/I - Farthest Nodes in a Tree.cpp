#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 5;
vector<pair<int, int>> g[N];
int node, mx;

void dfs(int u, int p, int sum) {
  if(sum > mx) {
    mx = sum;
    node = u;
  }
  for (auto [v, w]: g[u]) {
    if (v != p) {
      dfs(v, u, sum + w);
    }
  }
}

int cs = 0;
void solve() {
  int n; cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v, w; cin >> u >> v >> w;
    u++, v++;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  node = -1, mx = 0;
  dfs(1, 0, 0);
  int tmp = node;
  node = -1, mx = 0;
  dfs(tmp, 0, 0);

  cout << "Case " << ++cs << ": " << mx << '\n';

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