#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9;
int n;
vector<int> g[N];

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int leaf_cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 1) leaf_cnt++;
  }

  int ans = n;
  for (int i = 1; i <= n; i++) {
    int tmp = leaf_cnt;
    for (auto v : g[i]) {
      if (g[v].size() == 1) tmp--;
    }
    if (g[i].size() == 1) tmp--;
    ans = min(ans, tmp);
  }
  cout << ans << '\n';
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