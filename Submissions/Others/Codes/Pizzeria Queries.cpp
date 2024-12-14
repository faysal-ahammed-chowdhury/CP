#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, inf = 2e9;
int n, q, a[N];

struct ST {
  int tree[4 * N];
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = x;
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
} st, st2;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int ii = n - i + 1;
    st.upd(1, 1, n, i, a[i] + i);
    st2.upd(1, 1, n, i, a[i] + ii);
  }

  // cout << st2.query(1, 1, n, 1, 1) << '\n';

  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int i, k; cin >> i >> k;
      a[i] = k;
      st.upd(1, 1, n, i, i + k);
      int ii = n - i + 1;
      st2.upd(1, 1, n, i, ii + k);
    }
    else {
      int k; cin >> k;
      int l = st.query(1, 1, n, k + 1, n);
      int r = st2.query(1, 1, n, 1, k - 1);
      int ans = a[k];
      ans = min(ans, l - k);
      int ii = n - k + 1;
      ans = min(ans, r - ii);
      // cout << r - ii << ' ';
      cout << ans << '\n';
    }
  }

  return 0;
}