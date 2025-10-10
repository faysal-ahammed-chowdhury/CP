#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 9; 
string s;

struct node {
  int cnt0, cnt1;
  int ans1, ans2;
};

node merge(node &l, node &r) {
  if (l.cnt0 == -1) return r; 
  if (r.cnt0 == -1) return l; 
  node tmp;
  tmp.cnt0 = l.cnt0 + r.cnt0;
  tmp.cnt1 = l.cnt1 + r.cnt1;
  tmp.ans1 = l.ans1 + r.ans1;
  tmp.ans2 = l.ans2 + r.ans2;
  tmp.ans1 += l.cnt1 * r.cnt0;
  tmp.ans2 += l.cnt0 * r.cnt1;
  return tmp;
}

struct ST {
  node tree[4 * N];
  int lazy[4 * N];
  void push(int n, int b, int e) {
    if(lazy[n] == 0) return;
    swap(tree[n].cnt0, tree[n].cnt1);
    swap(tree[n].ans1, tree[n].ans2);
    if(b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] ^= lazy[n]; 
      lazy[r] ^= lazy[n]; 
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if(b == e) {
      tree[n].cnt0 = s[b] == '0'; 
      tree[n].cnt1 = s[b] == '1'; 
      tree[n].ans1 = 0; 
      tree[n].ans2 = 0; 
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
    if(b > j || e < i) return {-1, -1, -1, -1};
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

  int n; cin >> n;
  cin >> s;
  s = '.' + s;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') s[i] = '1';
    else s[i] = '0';
  }

  st.build(1, 1, n);

  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r;
    st.upd(1, 1, n, l, r);
    cout << st.query(1, 1, n, 1, n).ans1 << '\n';
  }

  return 0;
}