#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 2e5 + 9;
const long long inf = 1e18;
int a[N];

struct ST {
  long long tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if(lazy[n] == 0) return;
    tree[n] += lazy[n]; // change here
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
    tree[n] = min(tree[l], tree[r]); // change here
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
    tree[n] = min(tree[l], tree[r]); // change here
  }
  long long query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return inf; // return appropriate value
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    long long L = query(l, b, mid, i, j);
    long long R = query(r, mid + 1, e, i, j);
    return min(L, R); // change here
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
  cin.ignore();
  while(q--) {
    string s; getline(cin, s);
    stringstream ss(s);
    int l, r, v; ss >> l >> r;
    l++, r++;
    if(ss >> v) {
      if(l <= r) {
        st.upd(1, 1, n, l, r, v);
      }
      else {
        st.upd(1, 1, n, l, n, v);
        st.upd(1, 1, n, 1, r, v);
      }
    }
    else {
      if(l <= r) {
        cout << st.query(1, 1, n, l, r) << '\n';
      }
      else {
        cout << min(st.query(1, 1, n, l, n), st.query(1, 1, n, 1, r)) << '\n';
      }
    }
  }

  return 0;
}