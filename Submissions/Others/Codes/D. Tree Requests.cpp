#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 9, inf = 1e9;
vector<int> g[N];
int ans[N], par[N];
string s;
map<int, map<int, int>> mp[N];
vector<pair<int, int>> Q[N];

int find(int i) {
  return (i == par[i] ? i : par[i] = find(par[i]));
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return;
  if (mp[u].size() > mp[v].size()) swap(u, v);
  for (auto [lvl, mp2] : mp[u]) {
    for (auto [c, cnt] : mp2) {
      mp[v][lvl][c] += cnt;
    }
  }
  mp[u].clear();
  par[u] = v;
}

void dfs(int u, int p, int lvl) {
  mp[u][lvl][s[u]]++;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u, lvl + 1);
      merge(u, v);
    }
  }
  
  for (auto [dep, id] : Q[u]) {
    int x = 0;
    for (auto [c, cnt] : mp[find(u)][dep]) {
      x += cnt & 1;
    }
    ans[id] = x <= 1;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    par[i] = i;
    if (i >= 2) {
      int p; cin >> p;
      g[i].push_back(p);
      g[p].push_back(i);
    }
  }

  cin >> s;
  s = '#' + s;

  for (int i = 1; i <= q; i++) {
    int u, d; cin >> u >> d;
    Q[u].push_back({d, i});
  }

  dfs(1, 0, 1);
  for (int i = 1; i <= q; i++) {
    if (ans[i]) cout << "Yes\n";
    else cout << "No\n";
  }

  return 0;
}
