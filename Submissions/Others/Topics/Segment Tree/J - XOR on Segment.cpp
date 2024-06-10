#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e5 + 9, B = 30;
int a[N];

struct node {
  int arr[B];
};

node merge(node l, node r) {
  node ans;
  for(int k = 0; k < B; k++) {
    ans.arr[k] = l.arr[k] + r.arr[k];
  }
  return ans;
}

struct ST {
  node tree[4 * N];
  int lazy[4 * N];
  void push(int n, int b, int e) {
    if(lazy[n] == 0) return;
    for(int k = 0; k < B; k++) {
      if(lazy[n] & (1 << k)) {
        tree[n].arr[k] = (e - b + 1) - tree[n].arr[k];
      }
    }
    if(b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] ^= lazy[n]; // change here
      lazy[r] ^= lazy[n]; // change here
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if(b == e) {
      for(int k = 0; k < B; k++) {
        if(a[b] & (1 << k)) {
          tree[n].arr[k] = 1;
        }
        else {
          tree[n].arr[k] = 0;
        }
      }
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]); // change here
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if(b > j || e < i) return;
    if(b >= i && e <= j) {
      lazy[n] ^= x; // change here
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = merge(tree[l], tree[r]); // change here
  }
  node query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) {
      node tmp;
      for(int k = 0; k < B; k++) {
        tmp.arr[k] = 0;
      }
      return tmp;
    }
    if(b >= i && e <= j) {
      return tree[n];
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R); // change here
  }
} st;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st.build(1, 1, n);
  int q; cin >> q;
  while(q-- > 0) {
    int type; cin >> type;
    if(type == 1) {
      int l, r; cin >> l >> r;
      node ans = st.query(1, 1, n, l, r);
      long long x = 0;
      for(int k = 0; k < B; k++) {
        x += 1ll * (1 << k) * ans.arr[k];
      }
      cout << x << '\n';
    }
    else {
      int l, r, x; cin >> l >> r >> x;
      st.upd(1, 1, n, l, r, x);
    }
  }

  return 0;
}