#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 9;
int a[N];

struct ST {
  int tree[4 * N];
  pair<int, int> lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n].first == 0) return;
    if (lazy[n].second == 1) { // set
      tree[n] = lazy[n].first * (e - b + 1);
    }
    else { // add
      tree[n] += lazy[n].first * (e - b + 1);
    }
    if (b != e) {
      int l = n << 1, r = l + 1;
      if (lazy[l].second == 1) {
        if (lazy[n].second == 1) {
          lazy[l].first = lazy[n].first;
        }
        else {
          lazy[l].first += lazy[n].first;
        }
      }
      else {
        if (lazy[n].second == 1) {
          lazy[l].first = lazy[n].first;
          lazy[l].second = 1;
        }
        else {
          lazy[l].first += lazy[n].first;
        }
      }

      if (lazy[r].second == 1) {
        if (lazy[n].second == 1) {
          lazy[r].first = lazy[n].first;
        }
        else {
          lazy[r].first += lazy[n].first;
        }
      }
      else {
        if (lazy[n].second == 1) {
          lazy[r].first = lazy[n].first;
          lazy[r].second = 1;
        }
        else {
          lazy[r].first += lazy[n].first;
        }
      }
    }
    lazy[n].first = 0;
    lazy[n].second = -1;
  }
  void build(int n, int  b, int e) {
    lazy[n].first = 0;
    lazy[n].second = -1;
    if (b == e) {
      tree[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r];
  }
  void upd(int n, int b, int e, int i, int j, int type, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] = {x, type};
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, type, x);
    upd(r, mid + 1, e, i, j, type, x);
    tree[n] = tree[l] + tree[r];
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return L + R;
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
    int type, l, r; cin >> type >> l >> r;
    if (type == 1) {
      int x; cin >> x;
      st.upd(1, 1, n, l, r, 2, x);
    }
    else if (type == 2) {
      int x; cin >> x;
      st.upd(1, 1, n, l, r, 1, x);
    }
    else {
      cout << st.query(1, 1, n, l, r) << '\n';
    }
  }

  return 0;
}