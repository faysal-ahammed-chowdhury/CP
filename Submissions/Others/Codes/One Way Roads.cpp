#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 105;
vector<pii> g[N];
int n, x;

void dfs(int u, int p) {
  if (u == 1) return;
  for (auto [v, w] : g[u]) {
    if (v != p) {
      x += w;
      return dfs(v, u);
    }
  }
}

int cs;
void solve() {
  cin >> n;
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
  for (int i = 1; i <= n; i++) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back(make_pair(v, 0));
    g[v].push_back(make_pair(u, w));
  }
  int first = g[1][0].first;
  int second = g[1][1].first;
  x = 0;
  dfs(first, 1);
  int ans = g[1][0].second + x;
  x = 0;
  dfs(second, 1);
  ans = min(ans, g[1][1].second + x);
  cout << "Case " << ++cs << ": " << ans << '\n';
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