#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
int a[N];

struct node {
  ll ans;
  bool invalid;
  int cnt[42];
};

node merge(node &l, node &r) {
  if (l.invalid) return r;
  if (r.invalid) return l;
  node tmp;
  tmp.invalid = false;
  tmp.ans = l.ans + r.ans;
  for (int i = 1; i <= 40; i++) {
    tmp.cnt[i] = l.cnt[i] + r.cnt[i];
  }

  int pref[42];
  pref[0] = 0;
  for (int i = 1; i <= 40; i++) {
    pref[i] = pref[i - 1] + r.cnt[i];
  }
  for (int i = 1; i <= 40; i++) {
    ll here = 1ll * l.cnt[i] * pref[i - 1];
    tmp.ans += here;
  }

  return tmp;
}

struct ST {
  node tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n].ans = 0;
      tree[n].invalid = false;
      for (int val = 1; val <= 40; val++) {
        tree[n].cnt[val] = 0;
      }
      tree[n].cnt[a[b]] = 1;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]); 
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n].ans = 0; 
      tree[n].cnt[a[b]] = 0;
      tree[n].cnt[x] = 1;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = merge(tree[l], tree[r]);
  }
  node query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return {0, true};
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);

  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int l, r; cin >> l >> r;
      cout << st.query(1, 1, n, l, r).ans << '\n';
    }
    else {
      int i, x; cin >> i >> x;
      st.upd(1, 1, n, i, x);
      a[i] = x; 
    }
  }

  return 0;
}