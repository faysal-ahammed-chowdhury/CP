#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, inf = 1e9;
int n, m, a[N];

struct ST {
  pair<int, int> tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = make_pair(a[b], a[b]);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n].first = min(tree[l].first, tree[r].first);
    tree[n].second = max(tree[l].second, tree[r].second);
  }
  pair<int, int> query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return {inf, -inf}; 
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, i, j);
    pair<int, int> R = query(r, mid + 1, e, i, j);
    return make_pair(min(L.first, R.first), max(L.second, R.second));
  }
  bool all_x(int i, int j, int x) {
    pair<int, int> p = query(1, 1, n, i, j);
    return (p.first == p.second) and a[i] == x;
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);
 
  while (m--) {
    int i, j, x; cin >> i >> j >> x;
    if (st.all_x(i, j, x)) {
      cout << -1 << '\n';
      continue;
    }
    int l = i, r = j, ans = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[mid] != x) {
        ans = mid;
        break;
      }
      if (!st.all_x(l, mid, x)) {
        ans = mid;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}