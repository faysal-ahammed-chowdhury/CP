#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 9;
int n, k; 

struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = 1; 
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
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R); 
  }
} st;

bool ok(int l, int r, int sum) {
  // cout << l << ' ' << r << ' ' << st.query(1, 1, n, l, r) << '\n';
  return st.query(1, 1, n, l, r) >= sum;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  st.build(1, 1, n);

  int sz = n;
  int last = 1;
  while (sz > 0) {
    int skip = (k % sz) + 1;

    int l = last, r = n, idx = -1;
    int x = st.query(1, 1, n, last, n);
    if (skip > x) {
      // cout << "here: " << x << '\n';
      l = 1, r = n, skip = abs(x - skip);
      last = 1;
    }
    // cout << l << ' ' << r << ' ' << skip << '\n';
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok(last, mid, skip)) {
        idx = mid;
        r = mid - 1;
      }
      else l = mid + 1;
    }
    cout << idx << ' ';
    st.upd(1, 1, n, idx, 0);
    sz--;
    last = idx + 1;
    // break;
  }

  return 0;
}