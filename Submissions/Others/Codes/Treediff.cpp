#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 5e4 + 9, inf = 1e18;
vector<int> g[N];
int val[N], ans[N], par[N];
struct node {
  set<int> se;
  int ans;
} nodes[N];

int find(int i) {
  return (i == par[i] ? i : par[i] = find(par[i]));
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return;
  if (nodes[u].se.size() > nodes[v].se.size()) swap(u, v);
  nodes[v].ans = min(nodes[v].ans, nodes[u].ans);
  for (auto x : nodes[u].se) {
    if (nodes[v].se.find(x) != nodes[v].se.end()) {
      nodes[v].ans = 0;
    }
    else {
      nodes[v].se.insert(x);
      auto it1 = nodes[v].se.lower_bound(x);
      auto it2 = nodes[v].se.upper_bound(x);
      if (it1 != nodes[v].se.begin()) {
        --it1;
        nodes[v].ans = min(nodes[v].ans, abs(x - *it1));
      }
      if (it2 != nodes[v].se.end()) {
        nodes[v].ans = min(nodes[v].ans, abs(x - *it2));
      }
    }
  }
  nodes[u].se.clear();
  par[u] = v;
}

void dfs(int u, int p) {
  if (val[u] < inf) {
    nodes[u].se.insert(val[u]);
    nodes[u].ans = inf;
  }
  else {
    nodes[u].ans = inf;
  }
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      merge(u, v);
    }
  }
  ans[u] = nodes[find(u)].ans;
  if (ans[u] == inf) ans[u] = 2147483647;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    par[i] = i;
    val[i] = inf;
    if (i >= 2) {
      int p; cin >> p;
      g[i].push_back(p);
      g[p].push_back(i);
    }
  }

  for (int i = n - m + 1; i <= n; i++) {
    cin >> val[i];
  }

  dfs(1, 0);
  for (int i = 1; i <= n - m; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}
