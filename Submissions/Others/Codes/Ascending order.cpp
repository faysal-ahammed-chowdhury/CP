#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e5 + 9;
vector<int> g[N];
int disc[N], finish[N];
int a[N];
int timer;

struct MST { // merge sort tree
  vector<int> tree[4 * N];

  vector<int> merge(vector<int> &a, vector<int> &b) {
    int i = 0, j = 0;
    int n = a.size(), m = b.size();
    vector<int> ans;
    while (i < n and j < m) {
      if (a[i] <= b[j]) {
        ans.push_back(a[i]);
        i++;
      }
      else {
        ans.push_back(b[j]);
        j++;
      }
    }
    while (i < n) {
      ans.push_back(a[i]);
      i++;
    }
    while (j < m) {
      ans.push_back(b[j]);
      j++;
    }
    return ans;
  }

  void build(int n, int b, int e) {
    if (b == e) {
      vector<int> v;
      v.push_back(a[b]);
      tree[n] = v;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }

  int query(int n, int b, int e, int i, int j, int k) { // k er cheye boro cnt
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) {
      int idx = tree[n].end() - upper_bound(tree[n].begin(), tree[n].end(), k);
      return idx;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j, k);
    int R = query(r, mid + 1, e, i, j, k);
    return (L + R);
  }

  int query2(int n, int b, int e, int i, int j, int k) { // k er cheye choto cnt
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) {
      int idx = lower_bound(tree[n].begin(), tree[n].end(), k) - tree[n].begin();
      return idx;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query2(l, b, mid, i, j, k);
    int R = query2(r, mid + 1, e, i, j, k);
    return (L + R);
  }
} mst;

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
}

void dfs(int u, int p) {
  disc[u] = ++timer;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  finish[u] = timer;
}

int ans = 0;
void dfs_ans(int u, int p, int n) {
  int boro = 0, choto = 0;
  for (auto v : g[u]) {
    if (v != p) {
      int l = disc[v], r = finish[v];
      int here1 = mst.query(1, 1, n, l, r, a[disc[u]]);
      int here2 = mst.query2(1, 1, n, l, r, a[disc[u]]);

      ans += here1 * choto;
      ans += here2 * boro;

      boro += here1;
      choto += here2;
      dfs_ans(v, u, n);
    }
  }

  int l = disc[u], r = finish[u];
  // cout << l << ' ' << r << '\n';
  int here1 = mst.query(1, 1, n, 1, l - 1, a[disc[u]]) + mst.query(1, 1, n, r + 1, n, a[disc[u]]);
  int here2 = mst.query2(1, 1, n, 1, l - 1, a[disc[u]]) + mst.query2(1, 1, n, r + 1, n, a[disc[u]]);
  ans += here1 * choto;
  ans += here2 * boro;
}

void solve() {
  int n; cin >> n;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int p; cin >> p;
    g[p].push_back(i);
    g[i].push_back(p);
  }
  timer = 0;
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    a[disc[i]] = x;
  }

  // for (int i = 1; i <= n; i++) {
    // cout << a[i] << ' ';
  // }
  // cout << '\n';

  mst.build(1, 1, n);

  // cout << mst.query(1, 1, n, 2, 2, 8) << '\n';

  ans = 0;
  dfs_ans(1, 0, n);
  cout << ans << '\n';
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