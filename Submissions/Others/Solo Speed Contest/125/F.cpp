#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N];

struct node {
  int even, odd;
};

struct node merge(node l, node r) {
  node ans;
  ans.even = l.even + r.even;
  ans.odd = l.odd + r.odd;
  return ans;
}

struct ST {
  node tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      if (a[b] & 1) {
        tree[n].odd = 1;
        tree[n].even = 0;
      }
      else {
        tree[n].odd = 0;
        tree[n].even = 1;
      }
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]); // change here
  }
  node query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return {0, 0}; // return appropriate value
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R); // change this
  }
} st;

long long nC3(int n) {
  return 1ll * n * (n - 1) * (n - 2) / 6ll;
}

long long nC2(int n) {
  return 1ll * n * (n - 1) / 2ll;
}

void solve() {
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st.build(1, 1, n);
  while (q--) {
    int l, r; cin >> l >> r;
    node ans = st.query(1, 1, n, l, r);
    int even = ans.even;
    int odd = ans.odd;
    long long using_even = nC3(even);
    long long using_odd = nC2(odd) * even;
    long long ways = using_odd + using_even;
    cout << ways << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}