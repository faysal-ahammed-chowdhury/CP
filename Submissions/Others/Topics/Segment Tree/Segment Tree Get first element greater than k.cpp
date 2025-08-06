#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N];

struct ST {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    tree[n] = lazy[n];
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] = lazy[n];
      lazy[r] = lazy[n];
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if (b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] = x;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = max(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
  int get_first(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return -1;
    if (tree[n] <= x) return -1;

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

  return 0;
}