#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9, B = 320;
vector<int> g[N];
int n, c[N], a[N];
int timer, disc[N], finish[N];

struct BIT { //1-indexed
  int n; vector<int> t;
  BIT() {}
  BIT(int _n) {
    n = _n; t.assign(n + 1, 0);
  }
  int query(int i) {
    int ans = 0;
    for (; i >= 1; i -= (i & -i)) ans += t[i];
    return ans;
  }
  void upd(int i, int val) {
    if (i <= 0) return;
    for (; i <= n; i += (i & -i)) t[i] += val;
  }
  void upd(int l, int r, int val) {
    upd(l, val);
    upd(r + 1, -val);
  }
  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
} bit(N);

void dfs(int u, int p) {
  disc[u] = ++timer;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  finish[u] = timer;
}

struct query {
  int l, r, k, id;
  bool operator < (const query &x) const {
    if (l / B == x.l / B) return ((l / B) & 1) ? r > x.r : r < x.r;
    return l / B < x.l / B;
  }
} Q[N];

int cnt[N];

inline void add(int i) {
  int x = a[i];
  bit.upd(cnt[x], -1);
  ++cnt[x];
  bit.upd(cnt[x], 1);
}
inline void remove(int i) {
  int x = a[i];
  bit.upd(cnt[x], -1);
  --cnt[x];
  bit.upd(cnt[x], 1);
}
int ans[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);

  for (int i = 1; i <= n; i++) {
    a[disc[i]] = c[i];
  }

  for (int i = 1; i <= q; i++) {
    int v, k; cin >> v >> k;
    Q[i].l = disc[v];
    Q[i].r = finish[v];
    Q[i].k = k;
    Q[i].id = i;
  }

  sort(Q + 1, Q + q + 1);
  int l = 1, r = 0;
  for (int i = 1; i <= q; i++) {
    int L = Q[i].l, R = Q[i].r;
    int K = Q[i].k;
    if (R < l) {
      while (l > L) add(--l);
      while (l < L) remove(l++);
      while (r < R) add(++r);
      while (r > R) remove(r--);
    } else {
      while (r < R) add(++r);
      while (r > R) remove(r--);
      while (l > L) add(--l);
      while (l < L) remove(l++);
    }
    ans[Q[i].id] = bit.query(K, N - 1);
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << '\n';

  return 0;
}