#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200000 + 9;
vector<int> g[N];
int n, m, a[N], disc[N], finish[N], depth[N];
int timer, who[N];

void dfs(int u, int p) {
  disc[u] = ++timer;
  depth[u] = depth[p] + 1;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  finish[u] = timer;
}

struct ST {
  int tree[4 * N], lazy[4 * N], cnt[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    tree[n] += lazy[n] * (cnt[n]);
    // cout << n << ' ' << b << ' ' << e << ' ' << cnt[n] << ' ' << tree[n] << '\n';
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] += lazy[n];
      lazy[r] += lazy[n];
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e, bool even) {
    lazy[n] = 0;
    if (b == e) {
      tree[n] = 0;
      cnt[n] = (depth[who[b]] % 2 != even);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid, even);
    build(r, mid + 1, e, even);
    cnt[n] = cnt[l] + cnt[r];
    tree[n] = tree[l] + tree[r];
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] += x;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = tree[l] + tree[r];
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return L + R;
  }
} st1, st2;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);

  for (int i = 1; i <= n; i++) {
    who[disc[i]] = i;
  }

  st1.build(1, 1, n, true);
  st2.build(1, 1, n, false);

  while (m--) {
    int type, u; cin >> type >> u;
    if (type == 1) {
      int val; cin >> val;
      if (depth[u] % 2 == 0) {
        st1.upd(1, 1, n, disc[u], finish[u], val);
        st2.upd(1, 1, n, disc[u], finish[u], -val);
      }
      else {
        st1.upd(1, 1, n, disc[u], finish[u], -val);
        st2.upd(1, 1, n, disc[u], finish[u], val);
      }
    }
    else {
      int ans = st1.query(1, 1, n, disc[u], disc[u]);
      ans += st2.query(1, 1, n, disc[u], disc[u]);
      ans += a[u];
      cout << ans << '\n';
    }
  }

  // int ans = st1.query(1, 1, n, disc[4], disc[4]);
  // ans += st2.query(1, 1, n, disc[4], disc[4]);
  // ans += a[4];
  // cout << ans << '\n';

  return 0;
}