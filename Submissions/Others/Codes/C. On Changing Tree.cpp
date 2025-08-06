#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 9, mod = 1e9 + 7;
vector<ll> g[N];
int n, m, disc[N], finish[N], depth[N];
int timer, actual[N]; // actual[i] = node in index i

struct ST {
  int tree[4 * N], lazy[4 * N], cnt[4 * N], lazy2[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    int x = -(1ll * lazy[n] * cnt[n] % mod);
    if (x < 0) x += mod;
    tree[n] = (tree[n] + x) % mod;
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] = (lazy[l] + lazy[n]) % mod;
      lazy[r] = (lazy[r] + lazy[n]) % mod;

    }
    lazy[n] = 0;
  }
  void push2(int n, int b, int e) {
    if (lazy2[n] == 0) return;
    tree[n] = (tree[n] + (1ll * lazy2[n] * (e - b + 1) % mod)) % mod;
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy2[l] = (lazy2[l] + lazy2[n]) % mod;
      lazy2[r] = (lazy2[r] + lazy2[n]) % mod;
    }
    lazy2[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    lazy2[n] = 0;
    if (b == e) {
      tree[n] = 0;
      cnt[n] = depth[actual[b]];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = (tree[l] + tree[r]) % mod;
    cnt[n] = (cnt[l] + cnt[r]) % mod;
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    push2(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] = (lazy[n] + x) % mod;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = (tree[l] + tree[r]) % mod;
  }
  void upd2(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    push2(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy2[n] = (lazy2[n] + x) % mod;
      push2(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd2(l, b, mid, i, j, x);
    upd2(r, mid + 1, e, i, j, x);
    tree[n] = (tree[l] + tree[r]) % mod;
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    push2(n, b, e);
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) {
      return tree[n];
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R) % mod;
  }
} st;

void dfs(int u, int p) {
  disc[u] = ++timer;
  depth[u] = (p ? depth[p] + 1 : 0);
  actual[disc[u]] = u;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  finish[u] = timer;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 2; i <= n; i++) {
    int p; cin >> p;
    g[p].push_back(i);
    g[i].push_back(p);
  }

  dfs(1, 0);
  st.build(1, 1, n);

  int q; cin >> q;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int u, x, k; cin >> u >> x >> k;
      st.upd(1, 1, n, disc[u], finish[u], k % mod);
      int y = 1ll * depth[u] * k % mod;
      st.upd2(1, 1, n, disc[u], finish[u], (x + y) % mod);
    }
    else {
      int u; cin >> u;
      int ans = st.query(1, 1, n, disc[u], disc[u]);
      cout << ans << '\n';
    }
  }

  return 0;
}
