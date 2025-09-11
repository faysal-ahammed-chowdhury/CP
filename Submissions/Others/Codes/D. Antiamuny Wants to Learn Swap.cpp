#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5e5 + 9, inf = 2e9;

struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = inf;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = min(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = min(tree[n], x); 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = min(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return inf; 
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return min(L, R); 
  }
} st;

void solve() {
  int n, q; cin >> n >> q;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  stack<pair<int, int>> stk;
  int left[n + 1];
  for (int i = n; i >= 1; i--) {
    while (!stk.empty() and stk.top().first < a[i]) {
      left[stk.top().second] = i;
      stk.pop();
    }

    stk.push({a[i], i});
  }
  while (!stk.empty()) {
    left[stk.top().second] = -1;
    stk.pop();
  }

  int right[n + 1];
  for (int i = 1; i <= n; i++) {
    while (!stk.empty() and stk.top().first > a[i]) {
      right[stk.top().second] = i;
      stk.pop();
    }

    stk.push({a[i], i});
  }
  while (!stk.empty()) {
    right[stk.top().second] = -1;
    stk.pop();
  }

  st.build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    if (left[i] != -1 and right[i] != -1) {
      st.upd(1, 1, n, left[i], right[i]);
    }
  }

  while (q--) {
    int l, r; cin >> l >> r;
    int mn = st.query(1, 1, n, l, r);
    if (mn <= r) cout << "NO\n";
    else cout << "YES\n";
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