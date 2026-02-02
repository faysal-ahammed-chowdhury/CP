#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500000 + 9;
vector<bool> is_prime(N, true);

void sieve() {
  is_prime[1] = false;
  int lim = sqrt(N + 1);
  for (int i = 2; i <= lim; i++) {
    if (is_prime[i]) {
      for (int j = i + i; j < N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

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

bool ase[N];
vector<int> g[N];
int color[N];
bool vis[N];

void clr(int n) {
  memset(ase, false, sizeof ase);
  memset(vis, false, sizeof vis);
  memset(color, -1, sizeof color);
  for (int i = 0; i < N; i++) {
    g[i].clear();
  }
}

void dfs(int u, int col) {
  vis[u] = true;
  color[u] = col;
  for (auto v : g[u]) {
    if (!vis[v]) {
      dfs(v, !col);
    }
  }
}

int cs;
void solve() {
  int n; cin >> n;
  clr(n);
  int a[n + 1];
  int cnt = 0;
  vector<int> primes, composites;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ase[a[i]] = true;
  }
  sort(a + 1, a + n + 1);

  for (int i = 1; i <= n; i++) {
    for (int j = a[i]; j < N; j += a[i]) {
      if (ase[j] and is_prime[j / a[i]]) {
        g[a[i]].push_back(j);
        g[j].push_back(a[i]);
        // cout << a[i] << ' ' << j << '\n';
      }
    }
  }

  for (int i = 1; i <= a[n]; i++) {
    if (!vis[i]) {
      dfs(i, 0);
    }
  }

  vector<int> red, blue;
  for (int i = 1; i <= n; i++) {
    if (!ase[a[i]]) continue;
    if (color[a[i]] == 0) red.push_back(a[i]);
    else if (color[a[i]] == 1) blue.push_back(a[i]);
    else assert(false);
  }

  // for (auto x : red) {
  //   cout << x << ' ';
  // } cout << '\n';

  HopcroftKarp M(red.size(), blue.size());

  int id = 1;
  for (auto u : red) {
    for (auto v : g[u]) {
      int idx = lower_bound(blue.begin(), blue.end(), v) - blue.begin() + 1;
      M.add_edge(id, idx);
    }
    id++;
  }

  int ans = n - M.maximum_matching();
  cout << "Case " << ++cs << ": " << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}