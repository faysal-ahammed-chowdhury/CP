#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e5 + 9;
int a[N];
long long tree[4 * N], lazy[4 * N];

void push(int n, int b, int e) {
  if(lazy[n] == -1) return;
  tree[n] = lazy[n] * (e - b + 1);
  if(b != e) {
    int l = 2 * n, r = l + 1;
    lazy[l] = lazy[n];
    lazy[r] = lazy[n];
  }
  lazy[n] = -1;
}

void build(int n, int b, int e) {
  lazy[n] = -1;
  if(b == e) {
    tree[n] = a[b];
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = l + 1;
  build(l, b, mid);
  build(r, mid + 1, e);
  tree[n] = tree[l] + tree[r];
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
  tree[n] = tree[l] + tree[r];
}

long long query(int n, int b, int e, int i, int j) {
  push(n, b, e);
  if(b > j || e < i) return 0;
  if(b >= i && e <= j) return tree[n];
  int mid = (b + e) / 2, l = 2 * n, r = l + 1;
  long long L = query(l, b, mid, i, j);
  long long R = query(r, mid + 1, e, i, j);
  return L + R;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  build(1, 1, n);
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