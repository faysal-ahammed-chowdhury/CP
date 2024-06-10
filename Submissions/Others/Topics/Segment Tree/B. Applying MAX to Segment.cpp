#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e5 + 9;
int a[N], tree[4 * N], lazy[4 * N];

void push(int n, int b, int e) {
  if(lazy[n] == 0) return;
  tree[n] = max(tree[n], lazy[n]);
  if(b != e) {
    int l = 2 * n, r = l + 1;
    lazy[l] = max(lazy[l], lazy[n]);
    lazy[r] = max(lazy[r], lazy[n]);
  }
  lazy[n] = 0;
}

void build(int n, int b, int e) {
  if(b == e) {
    tree[n] = a[b];
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = l + 1;
  build(l, b, mid);
  build(r, mid + 1, e);
  tree[n] = max(tree[l], tree[r]);
}

void upd(int n, int b, int e, int i, int j, int x) {
  push(n, b, e);
  if(b > j || e < i) return;
  if(b >= i && e <= j) {
    lazy[n] = x;
    push(n, b, e);
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = l + 1;
  upd(l, b, mid, i, j, x);
  upd(r, mid + 1, e, i, j, x);
  tree[n] = max(tree[l], tree[r]);
}

int query(int n, int b, int e, int i, int j) {
  push(n, b, e);
  if(b > j || e < i) return 0;
  if(b >= i && e <= j) return tree[n];
  int mid = (b + e) / 2, l = 2 * n, r = l + 1;
  int L = query(l, b, mid, i, j);
  int R = query(r, mid + 1, e, i, j);
  return max(L, R);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while(m--) {
    int type; cin >> type;
    if(type == 1) {
      int l, r, v; cin >> l >> r >> v;
      l++;
      upd(1, 1, n, l, r, v);
    }
    else {
      int i; cin >> i;
      i++;
      cout << query(1, 1, n, i, i) << '\n';
    }
  }

  return 0;
}