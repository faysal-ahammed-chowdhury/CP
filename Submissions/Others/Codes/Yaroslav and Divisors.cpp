#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int pos[N], ans[N];
vector<int> pairs[N];
vector<pair<int, int>> Q[N];

struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = 0; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r]; 
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] += x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = tree[l] + tree[r]; 
  }
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0; 
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R); 
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    pos[x] = i;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      int l = min(pos[i], pos[j]);
      int r = max(pos[i], pos[j]);
      pairs[r].push_back(l);
    }
  }

  for (int i = 1; i <= q; i++) {
    int l, r; cin >> l >> r;
    Q[r].push_back({l, i});
  }

  st.build(1, 1, n);

  for (int r = 1; r <= n; r++) {
    for (auto l : pairs[r]) {
      // cnt[l]++;
      st.upd(1, 1, n, l, 1);
    }

    for (auto [l, id] : Q[r]) {
      int cur = 0;
      // for (int i = l; i <= r; i++) {
      //   cur += cnt[i];
      // }
      cur = st.query(1, 1, n, l, r);
      ans[id] = cur;
    }
  }

  for (int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}