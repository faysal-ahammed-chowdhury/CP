#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;

struct node {
  int cnt[64];
  node() {
    memset(cnt, 0, sizeof cnt);
  }
};

struct ST {
  node tree[4 * N];
  int lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    for (int k = 0; k < 64; k++) {
      if ((k ^ lazy[n]) > k) {
        swap(tree[n].cnt[k], tree[n].cnt[k ^ lazy[n]]);
      }
    }
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] ^= lazy[n];
      lazy[r] ^= lazy[n];
    }
    lazy[n] = 0;
  }
  node merge(node a, node b) {
    for (int k = 0; k < 64; k++) {
      a.cnt[k] += b.cnt[k];
    }
    return a;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if (b == e) {
      tree[n].cnt[0] = 1;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] ^= x;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = merge(tree[l], tree[r]);
  }
  node query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) {
      node tmp;
      return tmp;
    }
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  s = '.' + s;

  st.build(1, 1, n);

  for (int i = 1; i <= n; i++) {
    int x = (1 << (s[i] - 'a'));
    st.upd(1, 1, n, i, n, x);
  }

  int q; cin >> q;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int l, r; cin >> l >> r;
      node tmp = st.query(1, 1, n, l - 1, r);
      ll ans = 0;
      for (int k = 0; k < 64; k++) {
        int x = tmp.cnt[k];
        if (l == 1 and k == 0) x++;
        ans += (1ll * x * (x - 1)) / 2;
        // cout << x  << '\n';
      }
      cout << ans << '\n';
    }
    else {
      int i; cin >> i;
      char c; cin >> c;
      int mask = (1 << (s[i] - 'a'));
      mask ^= (1 << (c - 'a'));
      st.upd(1, 1, n, i, n, mask);
      s[i] = c;
    }
  }



  return 0;
}