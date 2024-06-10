#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
int n, m, k, max_possible_k;

int dfs(int u, int p, int val) {
  int ans = 1;
  for (auto v : g[u]) {
    if (v != p) {
      int x = dfs(v, u, val);
      if (x < val) ans += x;
      else max_possible_k++;
    }
  }
  if (u == 1 and ans < val) max_possible_k--;
  return ans;
}

bool ok(int val) {
  max_possible_k = 0;
  dfs(1, 0, val);
  return max_possible_k >= k;
}

void solve() {
  cin >> n >> k;
  m = n - 1;
  for (int i = 1; i <= m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int l = 1, r = n, ans = 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  cout << ans << '\n';

  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
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