#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
vector<int> g[N];
int col[N], ans[N], par[N];

struct node {
  map<int, int> mp;
  int mx, ans;
} nodes[N];

int find(int i) {
  return (i == par[i] ? i : par[i] = find(par[i]));
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return;
  if (nodes[u].mp.size() > nodes[v].mp.size()) swap(u, v);
  for (auto [c, cnt] : nodes[u].mp) {
    nodes[v].mp[c] += cnt;
    if (nodes[v].mp[c] > nodes[v].mx) {
      nodes[v].mx = nodes[v].mp[c];
      nodes[v].ans = c;
    }
    else if (nodes[v].mp[c] == nodes[v].mx) {
      nodes[v].ans += c;
    }
  }
  nodes[u].mp.clear();
  par[u] = v;
}

void dfs(int u, int p) {
  nodes[u].mp[col[u]] = 1;
  nodes[u].mx = 1;
  nodes[u].ans = col[u];
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      merge(u, v);
    }
  }
  ans[u] = nodes[find(u)].ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> col[i];
    par[i] = i;
  }

  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}
