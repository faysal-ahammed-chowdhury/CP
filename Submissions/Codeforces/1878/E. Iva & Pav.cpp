#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int n, a[N];

struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = a[b]; // change here
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = (tree[l] & tree[r]); // change here
  }
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return (1 << 30) - 1; // return appropriate value
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L & R); // change this
  }
} st;

int ok(int l, int r, int k) {
  int x = st.query(1, 1, n, l, r);
  return x >= k;
}

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st.build(1, 1, n);
  int q; cin >> q;
  while(q--) {
    int l, k; cin >> l >> k;
    int low = l, high = n, ans = -1;
    while(low <= high) {
      int mid = (low + high) / 2;
      if(ok(l, mid, k)) {
        ans = mid;
        low = mid + 1;
      }
      else {
        high = mid - 1;
      }
    }
    cout << ans << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}