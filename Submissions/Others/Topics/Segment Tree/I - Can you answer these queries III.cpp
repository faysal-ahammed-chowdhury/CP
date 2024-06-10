#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 5e4 + 9, inf = 2e9;
int a[N];

struct node {
  int max_subarray_sum;
  int max_suffix_sum;
  int max_prefix_sum;
  int total_sum;
};

node merge(node l, node r) {
  if(l.total_sum == inf) return r;
  if(r.total_sum == inf) return l;
  node ans;
  ans.max_subarray_sum = max(l.max_subarray_sum, r.max_subarray_sum);
  ans.max_subarray_sum = max(ans.max_subarray_sum, l.max_suffix_sum + r.max_prefix_sum);
  ans.max_prefix_sum = max(l.max_prefix_sum, l.total_sum + r.max_prefix_sum);
  ans.max_suffix_sum = max(r.max_suffix_sum, r.total_sum + l.max_suffix_sum);
  ans.total_sum = l.total_sum + r.total_sum;
  return ans;
}

struct ST {
  node tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = {a[b], a[b], a[b], a[b]}; // change here
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]); // change here
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = {x, x, x, x}; // change here
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = merge(tree[l], tree[r]); // change here
  }
  node query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return {inf, inf, inf, inf}; // return appropriate value
    if(b >= i && e <= j) {
      return tree[n];
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R); // change this
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st.build(1, 1, n);
  int q; cin >> q;
  while(q--) {
    int type; cin >> type;
    if(type == 0) {
      int i, x; cin >> i >> x;
      st.upd(1, 1, n, i, x);
    }
    else {
      int l, r; cin >> l >> r;
      node ans = st.query(1, 1, n, l, r);
      cout << ans.max_subarray_sum << '\n';
    }
  }

  return 0;
}