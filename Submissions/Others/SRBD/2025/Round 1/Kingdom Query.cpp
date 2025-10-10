#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;

const int N = 5e5 + 9, QQ = 5e5 + 9;
int n, a[N];
vector<int> g[N];
vector<pair<int, int>> Q[N];
int sz[N], par[N];
o_set<int> se[N];
int ans[QQ];

void clr(int n) {
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    sz[i] = 1;
    se[i].clear();
    Q[i].clear();
  }
}

int find(int i) {
  return (i == par[i] ? i : par[i] = find(par[i]));
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return;
  if (sz[u] > sz[v]) swap(u, v);
  for (auto x : se[u]) {
    se[v].insert(x);
  }
  se[u].clear();
  sz[v] += sz[u];
  par[u] = v;
}

void find_ans(int p, int k, int id) {
  // cout << p << ' ' << se[find(p)].size() << '\n';
  // for (auto x : se[par[p]]) {
  //   cout << x << ' ';
  // }
  // cout << '\n';
  int l = 1, r = se[find(p)].size();
  int idx = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    int x = *se[find(p)].find_by_order(mid - 1);
    bool ok = abs(x - mid) < k;
    if (ok) {
      idx = mid;
      l = mid + 1;
    }
    else {
      r = mid  - 1;
    }
  }
  int val = 0;
  if (idx != 0) val = *se[find(p)].find_by_order(idx - 1);
  int miss = abs(val - idx);
  // cout << idx << ' ' << miss << '\n';
  ans[id] = val + k - miss;
}

void dfs(int u, int p) {
  sz[u] = 1;
  se[u].insert(a[u]);
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      merge(u, v);
    }
  }

  // if (u != 5) return;
  for (auto [k, id] : Q[u]) {
    find_ans(u, k, id);
  }
}

void solve() {
  int q; cin >> n >> q;
  clr(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    par[i] = i;
  }
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int i = 1; i <= q; i++) {
    int p, k; cin >> p >> k;
    Q[p].push_back({k, i});
  }

  dfs(1, 0);

  for (int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
  }
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