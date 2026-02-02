#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct HopcroftKarp { // youknowwho
  static const int inf = 1e9;
  int n;
  vector<int> l, r, d;
  vector<vector<int>> g;
  HopcroftKarp(int _n, int _m) {
    n = _n;
    int p = _n + _m + 1;
    g.resize(p);
    l.resize(p, 0);
    r.resize(p, 0);
    d.resize(p, 0);
  }
  void add_edge(int u, int v) {
    g[u].push_back(v + n); //right id is increased by n, so is l[u]
  }
  bool bfs() {
    queue<int> q;
    for (int u = 1; u <= n; u++) {
      if (!l[u]) d[u] = 0, q.push(u);
      else d[u] = inf;
    }
    d[0] = inf;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : g[u]) {
        if (d[r[v]] == inf) {
          d[r[v]] = d[u] + 1;
          q.push(r[v]);
        }
      }
    }
    return d[0] != inf;
  }
  bool dfs(int u) {
    if (!u) return true;
    for (auto v : g[u]) {
      if (d[r[v]] == d[u] + 1 && dfs(r[v])) {
        l[u] = v;
        r[v] = u;
        return true;
      }
    }
    d[u] = inf;
    return false;
  }
  int maximum_matching() {
    int ans = 0;
    while (bfs()) {
      for (int u = 1; u <= n; u++) if (!l[u] && dfs(u)) ans++;
    }
    return ans;
  }
};

int cs;
void solve() {
  int m, f, v; cin >> m >> f >> v;
  vector<array<string, 2>> male, female;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= v; i++) {
    string s, t; cin >> s >> t;
    if (s[0] == 'M') {
      male.push_back({s, t});
      cnt1++;
    }
    else {
      female.push_back({s, t});
      cnt2++;
    }
  }

  HopcroftKarp M(cnt1, cnt2);

  for (int i = 0; i < male.size(); i++) {
    for (int j = 0; j < female.size(); j++) {
      if (male[i][0] == female[j][1] or male[i][1] == female[j][0]) {
        M.add_edge(i + 1, j + 1);
      }
    }
  }

  int ans = v - M.maximum_matching();
  cout << "Case " << ++cs << ": " << ans << '\n';
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