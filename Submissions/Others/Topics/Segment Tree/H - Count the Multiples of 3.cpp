#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e5 + 9;

struct node {
  int occurs[3];
};

node merge(node l, node r) {
  node ans;
  for(int i = 0; i < 3; i++) {
    ans.occurs[i] = l.occurs[i] + r.occurs[i];
  }
  return ans;
}

struct ST {
  node tree[4 * N];
  int lazy[4 * N];
  ST() {
    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));
  }
  void push(int n, int b, int e) {
    if(lazy[n] == 0) return;
    node tmp = tree[n];
    for(int i = 0; i < 3; i++) {
      tree[n].occurs[(i + lazy[n]) % 3] = tmp.occurs[i];
    }
    if(b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] = (lazy[l] + lazy[n]) % 3; // change here
      lazy[r] = (lazy[r] + lazy[n]) % 3; // change here
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if(b == e) {
      tree[n].occurs[0] = 1; // change here
      tree[n].occurs[1] = 0; // change here
      tree[n].occurs[2] = 0; // change here
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]); // change here
  }
  void upd(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return;
    if(b >= i && e <= j) {
      lazy[n] = 1; // change here
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j);
    upd(r, mid + 1, e, i, j);
    tree[n] = merge(tree[l], tree[r]); // change here
  }
  node query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return {0, 0, 0}; // return appropriate value
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R); // change here
  }
} st;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0; cin >> t;
  while(t--) {
    cout << "Case " << ++cs << ":\n"; 
    int n, q; cin >> n >> q;
    st.build(1, 1, n);
    while(q-- > 0) {
      int type; cin >> type;
      if(type == 0) {
        int i, j; cin >> i >> j;
        i++, j++;
        st.upd(1, 1, n, i, j);
      }
      else {
        int i, j; cin >> i >> j;
        i++, j++;
        cout << st.query(1, 1, n, i, j).occurs[0] << '\n';
      }
    }
  }

  return 0;
}