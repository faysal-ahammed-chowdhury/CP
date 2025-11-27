#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }

const int N = 2e5 + 9, LOG = 20, mod = 1e9;
int n;
pair<int, int> a[N], tmp[2 * N];
vector<int> g[N];
int par[N][LOG], depth[N], disc[N], finish[N], timer;

void dfs(int u, int p) {
  disc[u] = ++timer;
  par[u][0] = p;
  depth[u] = depth[p] + 1;
  for (int i = 1; i < LOG; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  finish[u] = ++timer;
}

int kth(int u, int k) {
  assert(k >= 0);
  for (int i = 0; i < LOG; i++) {
    if (CHECK(k, i)) u = par[u][i];
  }
  return u;
}

struct node {
  ll val;
  node *lc, *rc;
};
node *versions[N + N];
vector<node *> nodes;

node* build(int b, int e) {
  node *me = new node();
  nodes.push_back(me);
  if (b == e) {
    me->val = 0; // change here
    me->lc = NULL;
    me->rc = NULL;
    return me;
  }
  int mid = (b + e) >> 1;
  me->lc = build(b, mid);
  me->rc = build(mid + 1, e);
  me->val = me->lc->val + me->rc->val; // change here
  return me;
}

node *upd(node *me, int b, int e, int i, int x) {
  node *newme = new node();
  nodes.push_back(newme);
  if (b == e and b == i) {
    newme->val = me->val + x; // change here
    newme->lc = NULL;
    newme->rc = NULL;
    return newme;
  }
  int mid = (b + e) >> 1;
  if (i <= mid) {
    newme->lc = upd(me->lc, b, mid, i, x);
    newme->rc = me->rc;
  }
  else {
    newme->rc = upd(me->rc, mid + 1, e, i, x);
    newme->lc = me->lc;
  }
  newme->val = newme->lc->val + newme->rc->val; // change here
  return newme;
}

// returns kth element
int kth(node *me1, node *me2, int b, int e, int k) {
  if (b == e) {
    return b;
  }
  int cnt = me1->lc->val - me2->lc->val;
  int mid = (b + e) >> 1;
  if (cnt >= k) {
    return kth(me1->lc, me2->lc, b, mid, k);
  }
  return kth(me1->rc, me2->rc, mid + 1, e, k - cnt);
}

ll sum_query(node *me1, node *me2, int b, int e, int i, int j) {
  if (b > j || e < i) return 0; // return appropriate value
  if (b >= i and e <= j) return me1->val - me2->val; // change here
  int mid = (b + e) >> 1;
  ll L = sum_query(me1->lc, me2->lc, b, mid, i, j);
  ll R = sum_query(me1->rc, me2->rc, mid + 1, e, i, j);
  return (L + R);
}

void solve() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  vector<int> compressed;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second >> a[i].first;
    compressed.push_back(a[i].first);
  }
  sort(compressed.begin(), compressed.end());
  compressed.resize(unique(compressed.begin(), compressed.end()) - compressed.begin());


  for (int i = 1; i <= n; i++) {
    a[i].first = lower_bound(compressed.begin(), compressed.end(), a[i].first) - compressed.begin() + 1;
    tmp[disc[i]] = a[i];
    tmp[finish[i]] = a[i];
    tmp[finish[i]].second *= -1;
  }

  versions[0] = build(1, n);
  for (int i = 1; i <= n + n; i++) {
    versions[i] = upd(versions[i - 1], 1, n, tmp[i].first, +tmp[i].second);
  }

  ll last_ans = 0;
  int q; cin >> q;
  while (q--) {
    int u, d, pl, pu; cin >> u >> d >> pl >> pu;
    u = ((u + last_ans) % n) + 1;
    d = ((d + last_ans) % n);
    pl = ((pl + last_ans) % mod) + 1;
    pu = ((pu + last_ans) % mod) + 1;

    if (pl > pu) swap(pl, pu);
    pl = lower_bound(compressed.begin(), compressed.end(), pl) - compressed.begin() + 1;
    int old = pu;
    pu = upper_bound(compressed.begin(), compressed.end(), pu) - compressed.begin() + 1;
    pu--;

    int node = kth(u, d);
    if (node == 0) node++;

    int l = disc[node], r = disc[u];
    ll ans = sum_query(versions[r], versions[l - 1], 1, n, pl, pu);
    cout << ans << '\n';
    assert(ans >= 0);
    last_ans = ans;
  }

  // must clear memory
  for (node * me : nodes) {
    delete me;
  }
  nodes.clear();
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}
