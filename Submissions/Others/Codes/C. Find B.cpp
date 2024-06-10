#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 3e5 + 9;
int a[N];

struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = a[b] == 1; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r]; 
  }
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0; 
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R); 
  }
} st;

void solve() {
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ll pref[n + 1];
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }

  st.build(1, 1, n);

  while (q--) {
    int l, r; cin >> l >> r;
    int len = r - l + 1;
    ll x = pref[r] - pref[l - 1];
    x -= len;
    int must = 0;
    if (x < len) {
      must = len - x;
    }

    int cnt = st.query(1, 1, n, l, r);
    int rem = len - cnt;
    if (must > rem or len == 1) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}