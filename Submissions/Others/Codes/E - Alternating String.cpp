#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 9;
string s;

struct node {
  char first, last;
  bool bad;
};

node merge(node &l, node &r) {
  if (l.first == '-') return r;
  if (r.first == '-') return l;
  node ans;
  ans.bad = l.bad | r.bad | (l.last == r.first);
  ans.first = l.first;
  ans.last = r.last;
  return ans;
}

void flip(char &c) {
  if (c == '0') c = '1';
  else c = '0';
}

struct ST {
  node tree[4 * N];
  bool lazy[4 * N];
  void push(int n, int b, int e) {
    if(lazy[n] == 0) return;
    flip(tree[n].first);
    flip(tree[n].last);
    if(b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] ^= lazy[n]; 
      lazy[r] ^= lazy[n]; 
    }
    lazy[n] = 0;
  }
  void build(int n, int b, int e) {
    lazy[n] = 0;
    if(b == e) {
      tree[n] = {s[b], s[b], false};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return;
    if(b >= i && e <= j) {
      lazy[n] ^= 1;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j);
    upd(r, mid + 1, e, i, j);
    tree[n] = merge(tree[l], tree[r]);
  }
  node query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return {'-', '-', false}; 
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
  cin >> s;
  s = '.' + s;

  st.build(1, 1, n);
  while (q--) {
    int type, l, r; cin >> type >> l >> r;
    if (type == 1) {
      st.upd(1, 1, n, l, r);
    }
    else {
      bool bad = st.query(1, 1, n, l, r).bad;
      if (bad) cout << "No\n";
      else cout << "Yes\n";
    }
  }

  return 0;
}