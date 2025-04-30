#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005;
vector<int> g[N];
vector<int> comp[N];
int n, m, mx_w;
int w[N], b[N], dp[N][N];
bool vis[N];

void dfs(int u, int head) {
  comp[head].push_back(u);
  vis[u] = true;
  for (auto v : g[u]) {
    if (!vis[v]) dfs(v, head);
  }
}

int f(int i, int rem_w) {
  if (i > n) return 0;
  int &ans = dp[i][rem_w];
  if (ans != -1) return ans;
  ans = f(i + 1, rem_w);
  int tot_w = 0, tot_b = 0;
  for (auto x : comp[i]) {
    tot_w += w[x];
    tot_b += b[x];
    if (w[x] <= rem_w) ans = max(ans, b[x] + f(i + 1, rem_w - w[x]));
  }
  if (tot_w <= rem_w) ans = max(ans, tot_b + f(i + 1, rem_w - tot_w));
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> mx_w;
  for (int i = 1; i <= n; i++) cin >> w[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int u = 1; u <= n; u++) {
    if (!vis[u]) dfs(u, u);
  }

  memset(dp, -1, sizeof dp);
  cout << f(1, mx_w) << '\n';

  return 0;
}