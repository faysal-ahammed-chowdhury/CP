#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 9;
int a[N], l[N], r[N], d[N], op[N];

struct ST {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if(lazy[n] == 0) return;
    tree[n] += lazy[n] * (e - b + 1); // change here
    if(b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] += lazy[n]; // change here
      lazy[r] += lazy[n]; // change here
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if(b == e) {
      tree[n] = a[b]; // change here
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r]; // change here
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if(b > j || e < i) return;
    if(b >= i && e <= j) {
      lazy[n] += x; // change here
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = tree[l] + tree[r]; // change here
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return 0; // return appropriate value
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return L + R; // change here
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k; cin >> n >> m >> k;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= m; i++) {
    cin >> l[i] >> r[i] >> d[i];
  }
  for(int i = 1; i <= k; i++) {
    int x, y; cin >> x >> y;
    op[x]++;
    op[y + 1]--;
  }
  for(int i = 1; i <= m; i++) {
    op[i] += op[i - 1];
  }

  st.build(1, 1, n);

  for(int i = 1; i <= m; i++) {
    st.upd(1, 1, n, l[i], r[i], d[i] * op[i]);
  }

  for(int i = 1; i <= n; i++) {
    cout << st.query(1, 1, n, i, i) << ' ';
  }
  cout << '\n';

  return 0;
}