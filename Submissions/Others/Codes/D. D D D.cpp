#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, inf = 2e9;
vector<int> g[N];
int n, m, l, a[N];

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    a[i] = 0;
  }
}

vector<vector<int>> bfs(int s) {
  vector<vector<int>> dis(2, vector<int>(n + 1, inf));
  vector<vector<bool>> vis(2, vector<bool>(n + 1, false));
  dis[0][s] = 0;
  vis[0][s] = true;
  queue<array<int, 3>> q;
  q.push({0, s, 0});
  while (!q.empty()) {
    auto [d, u, parity] = q.front(); q.pop();
    int new_parity = (parity + 1) % 2;
    for (auto v : g[u]) {
      if (!vis[new_parity][v]) {
        int w = 1;
        dis[new_parity][v] = d + w;
        q.push({dis[new_parity][v], v, new_parity});
        vis[new_parity][v] = true;
      }
    }
  }
  return dis;
}

void solve() {
  cin >> n >> m >> l;
  clr(n);
  int sum_odd = 0, sum_even = 0, mn = inf;
  for (int i = 1; i <= l; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0) sum_even += a[i];
    else {
      sum_odd += a[i];
      mn = min(mn, a[i]);
    }
  }
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  auto dis = bfs(1);

  int tot = sum_odd + sum_even;
  int mx_odd = 0, mx_even = 0;
  if (tot % 2 == 0) {
    mx_even = tot;
    mx_odd = tot - mn;
  }
  else {
    mx_odd = tot;
    mx_even = tot - mn;
  }
  for (int i = 1; i <= n; i++) {
    if (dis[0][i] <= mx_even) cout << 1;
    else if (mn < inf and dis[1][i] <= mx_odd) cout << 1;
    else cout << 0;
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}