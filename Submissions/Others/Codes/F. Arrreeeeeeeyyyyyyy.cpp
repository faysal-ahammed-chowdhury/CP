#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 9;
int n, m, a[N], sorted[N], sorted_idx[N];

struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r];
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = tree[l] + tree[r];
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R);
  }
} st, st2;

bool ok(int len, int max_possible) {
  return st.query(1, 1, n, 1, len) <= max_possible;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sorted[i] = a[i];
  }

  sort(sorted + 1, sorted + n + 1);
  for (int i = 1; i <= n; i++) {
    int idx = lower_bound(sorted, sorted + n + 1, a[i]) - &sorted[0];
    sorted_idx[i] = idx;
  }

  st.build(1, 1, n);
  st2.build(1, 1, n);

  for (int i = 1; i <= n; i++) {
    if (a[i] > m) {
      cout << 0 << ' ';
    }
    else {
      int max_possible = m - a[i];
      int l = 0, r = n, ans = 0;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(mid, max_possible)) {
          ans = mid;
          l = mid + 1;
        }
        else {
          r = mid - 1;
        }
      }
      cout << st2.query(1, 1, n, 1, ans) + 1 << ' ';
    }
    st.upd(1, 1, n, sorted_idx[i], a[i]);
    st2.upd(1, 1, n, sorted_idx[i], 1);
  }
  cout << '\n';

  return 0;
}