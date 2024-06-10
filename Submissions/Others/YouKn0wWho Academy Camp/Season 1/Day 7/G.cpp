#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
int n, q, a[N];
map<int, vector<int>> mp;

vector<int> dfs(int u, int p) {
  vector<int> my;
  my.push_back(a[u]);
  for (auto v : g[u]) {
    if (v != p) {
      vector<int> dq = dfs(v, u);
      for (auto x : dq) {
        my.push_back(x);
      }
    }
  }
  sort(my.rbegin(), my.rend());
  while (my.size() > 20) my.pop_back();
  mp[u] = my;
  return my;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int m = n - 1;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);

  while (q--) {
    int v, k; cin >> v >> k;
    cout << mp[v][k - 1] << '\n';
  }

  return 0;
}