#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
vector<int> phi(N);

void phi_1_to_n() {
  for (int i = 0; i < N; i++)
    phi[i] = i;

  for (int i = 2; i < N; i++) {
    if (phi[i] == i) {
      for (int j = i; j < N; j += i)
        phi[j] -= phi[j] / i;
    }
  }
}

struct ST {
  ll tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = 0; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r]; 
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = tree[l] + tree[r]; 
  }
  ll query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0; 
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    ll L = query(l, b, mid, i, j);
    ll R = query(r, mid + 1, e, i, j);
    return (L + R); // change this
  }
} st;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  phi_1_to_n();

  int n, q; cin >> n >> q;
  st.build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    st.upd(1, 1, n, i, phi[x]);
  }

  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int i, x; cin >> i >> x;
      st.upd(1, 1, n, i, phi[x]);
    }
    else {
      int l, r; cin >> l >> r;
      cout << st.query(1, 1, n, l, r) << '\n';
    }
  }

  return 0;
}