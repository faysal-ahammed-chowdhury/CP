#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
const ll inf = 1e18;
int a[N];

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
      tree[n].tot_sum = a[b];
      tree[n].prefix_max = a[b];
      tree[n].suffix_max = a[b];
      tree[n].max_subarray_sum = a[b];
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
      tree[n].tot_sum = x;
      tree[n].prefix_max = x;
      tree[n].suffix_max = x;
      tree[n].max_subarray_sum = x;
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);
  while (q--) {
    int i, x; cin >> i >> x;
    st.upd(1, 1, n, i, x);
    cout << max(0ll, st.query(1, 1, n, 1, n).max_subarray_sum) << '\n';
  }

  return 0;
}