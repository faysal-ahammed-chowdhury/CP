#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 9;
int n, m, a[N], sorted[N], sorted_idx[N];

struct ST {
  pair<int, int> tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = {0, 0};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n].first = tree[l].first + tree[r].first;
    tree[n].second = tree[l].second + tree[r].second;
  }
  void upd(int n, int b, int e, int i, int x1, int x2) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n].first = x1;
      tree[n].second = x2;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x1, x2);
    upd(r, mid + 1, e, i, x1, x2);
    tree[n].first = tree[l].first + tree[r].first;
    tree[n].second = tree[l].second + tree[r].second;
  }
  pair<int, int> query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return {0, 0};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, i, j);
    pair<int, int> R = query(r, mid + 1, e, i, j);
    return {(L.first + R.first), (L.second + R.second)};
  }
} st;

bool ok(int len, int max_possible) {
  return st.query(1, 1, n, 1, len).first <= max_possible;
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
      cout << st.query(1, 1, n, 1, ans).second + 1 << ' ';
    }
    st.upd(1, 1, n, sorted_idx[i], a[i], 1);
  }
  cout << '\n';

  return 0;
}