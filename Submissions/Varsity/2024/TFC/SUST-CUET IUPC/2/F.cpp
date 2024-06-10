#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int a[N];

struct ST {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if(lazy[n] == 0) return;
    tree[n] = max(tree[n], lazy[n]);
    if(b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] = max(lazy[l], lazy[n]);
      lazy[r] = max(lazy[r], lazy[n]);
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if(b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if(b > j || e < i) return;
    if(b >= i && e <= j) {
      lazy[n] = max(lazy[n], x);
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = max(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  pair<int, int> a[n + 1];
  int b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
    b[i] = a[i].first;
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  vector<pair<int, int>> v;
  for (int i = 1; i <= n; i++) {
    int x = a[i].first + k;
    auto it = upper_bound(b + 1, b + n + 1, x) - (b + 1);
    v.push_back({i, it});
  }

  st.build(1, 1, n + 2);

  for (auto [x, y] : v) {
    int z = y - x + 1;
    st.upd(1, 1, n + 2, x, y, z);
  }

  int ans[n + 1];

  for (int i = 1; i <= n; i++) {
    ans[a[i].second] = st.query(1, 1, n + 2, i, i);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}