#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int n, a[N];
ll ans[N];
vector<int> g[N];

void clr(int n) {
  for (int i = 1; i <= n; i++) {
    ans[i] = -1;
    g[i].clear();
  }
}

void dfs(int u, int p, ll pp) {
  ans[u] = max(1ll * a[u], a[u] - a[p] + ans[pp]);
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u, p);
    }
  }
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0, 0);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
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