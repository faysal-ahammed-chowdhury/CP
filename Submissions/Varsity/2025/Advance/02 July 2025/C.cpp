#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9, inf = 1e9;
int n, a[N];
vector<int> g[N];
bool no;
pair<int, int> range[N];

pair<int, int> dfs(int u, int p) {
  pair<int, int> ret = {a[u], a[u]};
  int l = -inf, r = inf;
  for (auto v : g[u]) {
    if (v != p) {
      auto tmp = dfs(v, u);
      range[v] = tmp;
      if (tmp.first == inf) continue;
      if (abs(tmp.first) % 2 !=  abs(tmp.second) % 2) {
        no = true;
        return ret;
      }
      l = max(l, tmp.first - 1);
      r = min(r, tmp.second + 1);
    }
  }

  if (r == inf) {
    if (a[u] != inf) return {a[u], a[u]};
    return {inf, inf};
  }
  if (abs(l) % 2 != abs(r) % 2) {
    // cout << "ayhay\n";
    // cout << u << '\n';
    no = true;
    return ret;
  }
  // assert(abs(l) % 2 == abs(r) % 2);
  if (l > r) {
    no = true;
    return ret;
  }
  if (a[u] == inf) return {l, r};
  if (l <= a[u] and a[u] <= r and a[u] % 2 == abs(l) % 2) {
    return {a[u], a[u]};
  }
  no = true;
  return ret;
}

void dfs2(int u, int p, int val, int val2) {
  if (range[u].first == inf) {
    a[u] = val;
  }
  if (a[u] == inf) {
    if (range[u].first <= val) a[u] = val;
    else a[u] = range[u].first;
  }
  for (auto v : g[u]) {
    if (v != p) {
      dfs2(v, u, a[u] - 1, a[u] + 1);
    }
  }
}

void check(int u, int p, int val) {
  if (val != inf and abs(a[u] - val) != 1) no = true;
  for (auto v : g[u]) {
    if (v != p) {
      check(v, u, a[u]);
    }
  } 
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    a[i] = inf;
  }
  a[n] = inf;

  int k; cin >> k;
  int root = -1;
  while (k--) {
    int v, p; cin >> v >> p;
    a[v] = p;
    root = v;
  }

  auto tmp = dfs(root, 0);
  range[root] = tmp;  
  // cout << no << '\n';
  // cout << tmp.first << ' ' << tmp.second << '\n';
  if (no) {
    cout << "No\n";
    return 0;
  }

  dfs2(root, 0, 0, 0);
  check(root, 0, inf);
  if (no) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  for (int i = 1; i <= n; i++) {
    cout << a[i] << '\n';
  }
  // for (int i = 1; i <= n; i++) {
  //   cout << range[i].first << ' ' << ' ' << range[i].second << '\n';
  // }

  return 0;
}