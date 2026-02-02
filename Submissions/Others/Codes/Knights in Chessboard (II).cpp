#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int dx[] = { -1, -2, -2, -1, +1, +2, +2, +1};
int dy[] = { +2, +1, -1, -2, +2, +1, -1, -2};

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


int n, m;
bool valid(int x, int y) {
  return x >= 1 and x <= n and y >= 1 and y <= m;
}

int cs;
void solve() {
  int k; cin >> n >> m >> k;
  set<pair<int, int>> se;
  while (k--) {
    int x, y; cin >> x >> y;
    se.insert({x, y});
  }

  int white = (((m + 1) / 2) * ((n + 1) / 2)) + ((m / 2) * (n / 2));
  int black = (n * m) - white;
  HopcroftKarp M(white, black);

  vector<pair<int, int>> v1, v2;
  vector<pair<pair<int, int>, pair<int, int>>> match;

  for (int i = 1; i <= n; i++) {
    for (int j = (i & 1) ? 1 : 2; j <= m; j += 2) {
      v1.push_back({i, j});
      if (se.find({i, j}) != se.end()) continue;
      for (int k = 0; k < 8; k++) {
        int ii = i + dx[k];
        int jj = j + dy[k];
        if (valid(ii, jj) and se.find({ii, jj}) == se.end()) {
          match.push_back({{i, j}, {ii, jj}});
        }
      }
    }
    for (int j = (i & 1) ? 2 : 1; j <= m; j += 2) {
      v2.push_back({i, j});
    }
  }

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  map<pair<int, int>, int> mp1, mp2;
  for (int i = 0; i < v1.size(); i++) {
    auto p = v1[i];
    mp1[p] = i + 1;
  }
  for (int i = 0; i < v2.size(); i++) {
    auto p = v2[i];
    mp2[p] = i + 1;
  }

  for (auto [p, q] : match) {
    M.add_edge(mp1[p], mp2[q]);
    // cout << mp1[p] << ' ' << mp2[q] << '\n';
  }

  int ans = (n * m) - se.size() - M.maximum_matching();
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