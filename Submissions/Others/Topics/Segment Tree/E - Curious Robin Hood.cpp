#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

#define ll long long
const int N = 1e5 + 9;
int a[N];

struct ST {
  ll tree[4 * N];
  ST() {
    memset(tree, 0, sizeof(tree));
  }
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r]; // change here
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      a[b] = x;
      tree[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = tree[l] + tree[r]; // change here
  }
  void upd_add(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      a[b] += x;
      tree[n] += x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd_add(l, b, mid, i, x);
    upd_add(r, mid + 1, e, i, x);
    tree[n] = tree[l] + tree[r]; // change here
  }
  ll query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0; // return appropriate value
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    ll L = query(l, b, mid, i, j);
    ll R = query(r, mid + 1, e, i, j);
    return (L + R); // change this
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0; cin >> t;
  while(t--) {
    ST st;
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    st.build(1, 1, n);

    cout << "Case " << ++cs << ":\n";
    while(q--) {
      int type; cin >> type;
      if(type == 1) {
        int i; cin >> i; i++;
        cout << a[i] << '\n';
        st.upd(1, 1, n, i, 0);
      }
      else if(type == 2) {
        int i, x; cin >> i >> x; i++;
        st.upd_add(1, 1, n, i, x);
      }
      else {
        int i, j; cin >> i >> j; i++, j++;
        cout << st.query(1, 1, n, i, j) << '\n';
      }
    }
  }

  return 0;
}