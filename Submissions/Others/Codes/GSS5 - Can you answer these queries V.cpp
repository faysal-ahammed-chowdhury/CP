#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e4 + 9, K = 20, inf = 1e18;
int n, a[N], pref[N], tree_mx[N][K], tree_mn[N][K];

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tree_mn[i][0] = pref[i];
    tree_mx[i][0] = pref[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree_mn[i][k] = min(tree_mn[i][k - 1], tree_mn[i + (1 << (k - 1))][k - 1]);
      tree_mx[i][k] = max(tree_mx[i][k - 1], tree_mx[i + (1 << (k - 1))][k - 1]);
    }
  }
}

int query_mn(int l, int r) {
  int k = log2_floor(r - l + 1);
  return min(tree_mn[l][k], tree_mn[r - (1 << k) + 1][k]);
}

int query_mx(int l, int r) {
  int k = log2_floor(r - l + 1);
  return max(tree_mx[l][k], tree_mx[r - (1 << k) + 1][k]);
}

struct node {
  ll tot_sum;
  ll prefix_max, suffix_max;
  ll max_subarray_sum;
};

node merge(node l, node r) {
  if (l.tot_sum == -inf) return r;
  if (r.tot_sum == -inf) return l;
  node ans;
  ans.max_subarray_sum = max(l.max_subarray_sum, r.max_subarray_sum);
  ans.max_subarray_sum = max(ans.max_subarray_sum, l.suffix_max + r.prefix_max);
  ans.tot_sum = l.tot_sum + r.tot_sum;
  ans.prefix_max = l.prefix_max;
  if (l.tot_sum + r.prefix_max >= l.prefix_max) {
    ans.prefix_max = l.tot_sum + r.prefix_max;
  }
  ans.suffix_max = r.suffix_max;
  if (r.tot_sum + l.suffix_max >= r.suffix_max) {
    ans.suffix_max = r.tot_sum + l.suffix_max;
  }
  return ans;
}

struct ST {
  node tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = {a[b], a[b], a[b], a[b]};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] = {x, x, x, x};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = merge(tree[l], tree[r]);
  }
  node query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return { -inf, -inf, -inf, -inf};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
  }
} st;

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }

  st.build(1, 1, n);
  build(n);

  int q; cin >> q;
  while (q--) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if (y2 < x1) {
      cout << 0 << '\n';
      continue;
    }
    if (y1 <= x2) {
      int mx = query_mx(x2, y2);
      int mn = query_mn(x1 - 1, y1 - 1);
      cout << mx - mn << '\n';
      continue;
    }
    if (x1 <= x2 and x2 <= y1 and y1 <= y2) {
      int ans = st.query(1, 1, n, x2, y1).max_subarray_sum;
      int mx = query_mx(x2, y2);
      int mn = query_mn(x1 - 1, x2 - 1);
      ans = max(ans, mx - mn);
      mx = query_mx(y1, y2);
      mn = query_mn(x1 - 1, y1 - 1);
      ans = max(ans, mx - mn);
      cout << ans << '\n';
      continue;
    }
    if (x2 <= x1 and x1 <= y2 and y2 <= y1) {
      int ans = st.query(1, 1, n, x1, y2).max_subarray_sum;
      cout << ans << '\n';
      continue;
    }
    if (x2 <= x1 and y1 <= y2) {
      int ans = st.query(1, 1, n, x1, y1).max_subarray_sum;
      int mx = query_mx(y1, y2);
      int mn = query_mn(x1 - 1, y1 - 1);
      ans = max(ans, mx - mn);
      cout << ans << '\n';
      continue;
    }

    if (x1 <= x2 and y2 <= y1) {
      int ans = st.query(1, 1, n, x2, y2).max_subarray_sum;
      int mx = query_mx(x2, y2);
      int mn = query_mn(x1 - 1, x2 - 1);
      ans = max(ans, mx - mn);
      cout << ans << '\n';
      continue;
    }
    assert(false);
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