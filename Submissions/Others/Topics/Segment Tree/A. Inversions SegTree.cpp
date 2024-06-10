#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

#define int long long
const int N = 1e5 + 9;
int a[N];

struct ST {
  int tree[4 * N];
  ST() {
    memset(tree, 0, sizeof(tree));
  }
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = 0; // change here
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
      tree[n] += x; // change here
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = tree[l] + tree[r]; // change here
  }
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0; // return appropriate value
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R); // change this
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st.build(1, 1, n);

  for(int i = 1; i <= n; i++) {
    st.upd(1, 1, n, a[i], 1);
    cout << st.query(1, 1, n, a[i] + 1, n) << ' ';
  }
  cout << '\n';

  return 0;
}