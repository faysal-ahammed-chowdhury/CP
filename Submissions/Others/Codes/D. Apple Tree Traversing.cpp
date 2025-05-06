#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int n, m;
vector<int> g[N];
int par[N];
vector<bool> used(N);

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    par[i] = -1;
    g[i].clear();
    used[i] = false;
  }
}

pair<int, int> dfs(int u, int p) {
  par[u] = p;
  pair<int, int> ans = {1, u};
  for (auto v : g[u]) {
    if (v != p and !used[v]) {
      auto tmp = dfs(v, u);
      tmp.first++;
      ans = max(ans, tmp);
    }
  }
  // cout << u << ' ' << ans.first << ' ' << ans.second << '\n';
  return ans;
}

void solve() {
  cin >> n;
  clr(n);
  m = n - 1;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int cnt = 0;
  vector<array<int, 3>> ans;
  while (cnt < n) {
    for (int i = 1; i <= n; i++) {
      if (!used[i]) {
        auto [d1, one_ending] = dfs(i, -1);
        auto [d2, another_ending] = dfs(one_ending, -1);
        ans.push_back({d2, max(one_ending, another_ending), min(one_ending, another_ending)});

        int cur = another_ending;
        while (cur != -1) {
          cnt++;
          used[cur] = true;
          cur = par[cur];
        }
      }
    }
  }

  sort(ans.rbegin(), ans.rend());

  for (auto [d, u, v] : ans) {
    cout << d << ' ' << u << ' ' << v << ' ';
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