#include <bits/stdc++.h>
using namespace std;
#define int long long

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }

const int N = 2e5 + 9, LOG = 30, inf = 1e15, mod = 1e9;
int32_t n;
pair<int32_t, int32_t> a[N], tmp[2 * N];
vector<int32_t> g[N];
int32_t par[N][LOG], depth[N], disc[N], finish[N], timer;

void dfs(int32_t u, int32_t p) {
  disc[u] = ++timer;
  par[u][0] = p;
  depth[u] = depth[p] + 1;
  for (int32_t i = 1; i < LOG; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  finish[u] = ++timer;
}

int32_t kth(int32_t u, int32_t k) {
  assert(k >= 0);
  for (int32_t i = 0; i < LOG; i++) {
    if (CHECK(k, i)) u = par[u][i];
  }
  return u;
}

struct MST { // merge sort tree
  vector<array<int, 3>> tree[4 * (N + N)];

  vector<array<int, 3>> merge(vector<array<int, 3>> &a, vector<array<int, 3>> &b) {
    int i = 0, j = 0;
    int n = a.size(), m = b.size();
    vector<array<int, 3>> ans;
    int sum = 0;
    while (i < n and j < m) {
      if (a[i] <= b[j]) {
        sum += tmp[a[i][2]].second;
        ans.push_back({a[i][0], sum, a[i][2]});
        i++;
      }
      else {
        sum += tmp[b[j][2]].second;
        ans.push_back({b[j][0], sum, b[j][2]});
        j++;
      }
    }
    while (i < n) {
      sum += tmp[a[i][2]].second;
      ans.push_back({a[i][0], sum, a[i][2]});
      i++;
    }
    while (j < m) {
      sum += tmp[b[j][2]].second;
      ans.push_back({b[j][0], sum, b[j][2]});
      j++;
    }
    return ans;
  }

  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = {{tmp[b].first, tmp[b].second, b}};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
    // cout << "here: " << b << ' ' << e << '\n';
    // for (auto [x, y, _] : tree[n]) {
    //   cout << x << ' ' << y << '\n';
    // }
  }

  int query(int n, int b, int e, int i, int j, int k) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) {
      array<int, 3> here = {k, inf, inf};
      auto it = upper_bound(tree[n].begin(), tree[n].end(), here);
      if (it != tree[n].begin()) --it;
      else return 0;
      here = *it;
      // cout << "here: " << here[1] << ' ' << e << '\n';
      // for (auto [x, y, _] : tree[n]) {
      //   cout << x << ' ' << y << '\n';
      // }
      return here[1];
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j, k);
    int R = query(r, mid + 1, e, i, j, k);
    return (L + R);
  }
} mst;


void solve() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second >> a[i].first;
  }

  for (int i = 1; i <= n; i++) {
    tmp[disc[i]] = a[i];
    tmp[finish[i]] = a[i];
    tmp[finish[i]].second *= -1;
    // if (disc[i] <= 0 or disc[i] > n) {
    //   cout << "ahare\n";
    // }
    // cout << i << ' ' << disc[i] << ' ' << finish[i] << '\n';
  }

  // for (int i = 1; i <= n + n; i++) {
  //   cout << tmp[i].second << ' ';
  // }

  // cout << tmp[6].first << ' ' << tmp[6].second << '\n';
  mst.build(1, 1, n + n);
  // cout << mst.query(1, 1, n, 1, 3, 1) << '\n';
  // return;

  int last_ans = 0;
  int q; cin >> q;
  while (q--) {
    int u, d, pl, pu; cin >> u >> d >> pl >> pu;
    u = ((u + last_ans) % n) + 1;
    d = ((d + last_ans) % n);
    pl = ((pl + last_ans) % mod) + 1;
    pu = ((pu + last_ans) % mod) + 1;

    if (pl > pu) swap(pl, pu);

    int node = kth(u, d);
    if (node == 0) node++;

    int l = disc[node], r = disc[u];
    // cout << l << ' ' << r << '\n';
    int ans = mst.query(1, 1, n + n, l, r, pu) - mst.query(1, 1, n + n, l, r, pl - 1);
    cout << ans << '\n';
    assert(ans >= 0);
    last_ans = ans;
  }
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
