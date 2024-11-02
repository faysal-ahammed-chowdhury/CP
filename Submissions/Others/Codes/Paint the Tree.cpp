#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 9;
const ll inf = 1e18;
vector<int> g[N];
int c[3][N], n;
ll ans[N];
vector<int> a({0, 1, 2}), v;

ll dfs(int u, int p, int now) {
  ll ans = c[a[now]][u];
  for (auto v : g[u]) {
    if (v != p) {
      ans += dfs(v, u, (now + 1) % 3);
    }
  }
  return ans;
}

void dfs2(int u, int p, int now) {
  ans[u] = v[now];
  for (auto v : g[u]) {
    if (v != p) {
      dfs2(v, u, (now + 1) % 3);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[0][i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[1][i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[2][i];
  }
  bool not_possible = false;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    if (g[u].size() > 2) not_possible = true;
    if (g[v].size() > 2) not_possible = true;
  }
  if (not_possible) {
    cout << -1 << '\n';
    return 0;
  }

  int root = -1;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 1) {
      root = i;
      break;
    }
  }

  a = {0, 1, 2};
  ll cost = inf;
  do {
    ll cur = dfs(root, 0, 0);
    if (cur <= cost) {
      cost = cur;
      v = a;
    }
  } while (next_permutation(a.begin(), a.end()));
  cout << cost << '\n';
  ll x = 0;
  dfs2(root, 0, 0);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] + 1 << ' ';
  }
  cout << '\n';

  return 0;
}