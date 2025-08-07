#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 9;
int a[N];

struct ST {
  int tree[4 * N];
  void build(int n, int  b, int e) {
    if (b == e) {
      tree[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = __gcd(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = __gcd(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return __gcd(L, R);
  }
  int get_first(int n, int b, int e, int i, int j, int x) {
    if (b > j || e < i) return -1;
    if (tree[n] % x == 0) return -1;

    if (b == e) return b;

    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int left = get_first(l, b, mid, i, j, x);
    if (left != -1) return left;
    return get_first(r, mid + 1, e, i , j, x);
  }
} st;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);

  int q; cin >> q;
  while (q--) {
    int T; cin >> T;
    if (T == 1) {
      int l, r, x; cin >> l >> r >> x;
      int idx = st.get_first(1, 1, n, l, r, x);
      if (idx == -1) cout << "YES\n";
      else {
        int val1 = st.query(1, 1, n, l, idx - 1);
        int val2 = st.query(1, 1, n, idx + 1, r);
        if (val1 % x == 0 and val2 % x == 0) cout << "YES\n";
        else cout << "NO\n";
      }
    }
    else {
      int i, x; cin >> i >> x;
      st.upd(1, 1, n, i, x);
    }
  }

  return 0;
}