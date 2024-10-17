#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 9, inf = 2e9;
int a[N];

struct MST { // merge sort tree
  o_set<array<int, 2>> tree[4 * N];

  o_set<array<int, 2>> merge(o_set<array<int, 2>> a, o_set<array<int, 2>> b) {
    int i = 0, j = 0;
    int n = a.size(), m = b.size();
    o_set<array<int, 2>> ans;
    for (auto x : a) ans.insert(x);
    for (auto x : b) ans.insert(x);
    return ans;
  }

  void build(int n, int b, int e) {
    if (b == e) {
      tree[n].insert({a[b], b});
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }

  void upd(int n, int b, int e, int i, int x) {
    if (b == e) {
      tree[n].erase({a[b], b});
      tree[n].insert({x, b});
      a[b] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    tree[n].erase({a[i], i});
    tree[n].insert({x, i});
    if (i <= mid) upd(l, b, mid, i, x);
    else upd(r, mid + 1, e, i, x);
  }

  int query(int n, int b, int e, int i, int j, int k) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) {
      int idx = tree[n].order_of_key({k, inf});
      return idx;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j, k);
    int R = query(r, mid + 1, e, i, j, k);
    return (L + R);
  }
} mst;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int q; cin >> q;
  int end = n + q;
  mst.build(1, 1, end);
  int cur = n + 1;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int x; cin >> x;
      mst.upd(1, 1, end, cur, x);
      cur++;
    }
    else if (type == 2) {
      mst.upd(1, 1, end, cur - 1, inf);
      cur--;
    }
    else {
      int i, j, k; cin >> i >> j >> k;
      int l = 1, r = 1e9, ans = -1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (mst.query(1, 1, end, i, j, mid) < k) {
          ans = mid;
          r = mid - 1;
        }
        else {
          l = mid + 1;
        }
      }
      cout << ans << '\n';
    }
  }

  return 0;
}
