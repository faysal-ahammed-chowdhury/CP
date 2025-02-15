#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, M = 4e5 + 9;
int a[N], ans[N];
vector<pair<int, int>> Q[N];

struct ST {
  int tree[4 * M + 10];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = max(tree[n], x);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = max(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
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

  int n, q; cin >> n >> q;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; // a[i] value must be >= 2
    v.push_back(a[i]);
  }

  for (int i = 1; i <= q; i++) {
    int r, x; cin >> r >> x;
    v.push_back(x);
    Q[r].push_back({x, i});
  }

  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 2;
  }

  for (int i = 1; i <= n; i++) {
    for (auto &[x, id] : Q[i]) {
      x = lower_bound(v.begin(), v.end(), x) - v.begin() + 2;
    }
  }

  st.build(1, 1, M);

  for (int i = 1; i <= n; i++) {
    int cur = 1;
    if (a[i] != 1) {
      int mx = st.query(1, 1, M, 1, a[i] - 1);
      mx++;
      cur = max(cur, mx);
    }
    st.upd(1, 1, M, a[i], cur);

    for (auto [x, id] : Q[i]) {
      ans[id] = st.query(1, 1, M, 1, x);
    }
  }

  for (int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}