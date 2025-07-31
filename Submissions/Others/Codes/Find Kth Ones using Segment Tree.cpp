#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9; // change here
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
  int find_kth(int n, int b, int e, int i, int j, int k) {
    if (b > j || e < i) return -1;
    if (tree[n] < k) return -1;
    if (b == e) return b;
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    if (tree[l] >= k) {
      return find_kth(l, b, mid, i, j, k);
    }
    return find_kth(r, mid + 1, e, i, j, k - tree[l]);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);

  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int i; cin >> i;
      ++i; 
      a[i] ^= 1;
      st.upd(1, 1, n, i, a[i]);
    }
    else {
      int k; cin >> k;
      ++k;
      int x = st.find_kth(1, 1, n, 1, n, k);
      cout << --x << '\n';
    }
  }

  return 0;
}