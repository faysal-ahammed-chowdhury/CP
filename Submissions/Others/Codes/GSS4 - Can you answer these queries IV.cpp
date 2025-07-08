#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, inf = 1e9;
ll a[N];

struct ST {
  ll tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r];
  }
  void upd(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return;
    if (e - b + 1 == tree[n]) return;
    if (b == e) {
      ll x = sqrtl(tree[n]);
      while (x * x < tree[n]) x++;
      while (x * x > tree[n]) x--;
      tree[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j);
    upd(r, mid + 1, e, i, j);
    tree[n] = tree[l] + tree[r];
  }
  ll query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    ll L = query(l, b, mid, i, j);
    ll R = query(r, mid + 1, e, i, j);
    return L + R;
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, cs = 0;
  while (cin >> n) {
    cout << "Case #" << ++cs << ":\n";
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    st.build(1, 1, n);
    int q; cin >> q;
    while (q--) {
      int type, l, r; cin >> type >> l >> r;
      if (l > r) swap(l, r);
      if (type == 0) {
        st.upd(1, 1, n, l, r);
      }
      else {
        cout << st.query(1, 1, n, l, r) << '\n';
      }
    }
    cout << '\n';
  }

  return 0;
}