#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int long long

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

const int N = 1e5 + 9, inf = 1e18;
vector<int> g[N];
int n, a[N], par[N], sz[N];
gp_hash_table<int, int, custom_hash> ms[N];

struct ST {
  vector<int> tree;
  ST() {
  }
  ST(int sz) {
    tree.resize(4 * sz + 5);
  }
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = min(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = min(tree[l], tree[r]);
  }
  int get_first(int n, int b, int e, int l, int r) {
    if (b > r || e < l) return -1;
    if (tree[n] != 0) return -1;

    if (b == e) return b;

    int tm = b + (e - b) / 2;
    int left = get_first(2 * n, b, tm, l, r);
    if (left != -1) return left;
    return get_first(2 * n + 1, tm + 1, e, l , r);
  }
};
ST st[N];

void dfs(int u, int p) {
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
  st[u] = ST(sz[u]);
  st[u].build(1, 0, sz[u]);
}

void upd(int u, int x, int y) {
  if (u == -1) return;
  if (y != -1 and y <= sz[u]) {
    ms[u][y]--;
    if (ms[u][y] == 0) st[u].upd(1, 0, sz[u], y, 0);
  }
  if (x <= sz[u]) {
    ms[u][x]++;
    st[u].upd(1, 0, sz[u], x, 1);
  }
  upd(par[u], x, y);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int root;
  for (int i = 1; i <= n; i++) {
    cin >> par[i];
    if (par[i] == -1) root = i;
    else {
      g[i].push_back(par[i]);
      g[par[i]].push_back(i);
    }
  }

  dfs(root, 0);

  for (int i = 1; i <= n; i++) {
    ll x; cin >> x;
    a[i] = x;
    upd(i, x, -1);
  }

  int q; cin >> q;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int u, x; cin >> u >> x;
      upd(u, x, a[u]);
      a[u] = x;
    }
    else {
      int u; cin >> u;
      int ans = st[u].get_first(1, 0, sz[u], 0, sz[u]);
      if (ans == -1) {
        ans = sz[u];
      }
      cout << ans << '\n';
    }
  }

  return 0;
}