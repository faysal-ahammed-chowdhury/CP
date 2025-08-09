#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int mod = 998244353;
const int N = 2e5 + 9;
int a[N], arr[N];

struct ST {
  int tree[4 * N], tree1[4 * N], tree2[4 * N];
  int lazy1[4 * N], lazy2[4 * N];
  void push(int n, int b, int e) {
    if (lazy1[n] == 0 and lazy2[n] == 0) return;

    if (lazy1[n] != 0) {
      tree1[n] += 1ll * lazy1[n] * (e - b + 1) % mod;
      tree1[n] %= mod;
      tree[n] += 1ll * lazy1[n] * tree2[n] % mod;
      tree[n] %= mod;
      if (b != e) {
        int l = n << 1, r = l + 1;
        lazy1[l] += lazy1[n];
        lazy1[l] %= mod;
        lazy1[r] += lazy1[n];
        lazy1[r] %= mod;
      }
      lazy1[n] = 0;
    }

    if (lazy2[n] != 0) {
      tree2[n] += lazy2[n] * (e - b + 1);
      tree2[n] %= mod;
      tree[n] += lazy2[n] * tree1[n];
      tree[n] %= mod;
      if (b != e) {
        int l = n << 1, r = l + 1;
        lazy2[l] += lazy2[n];
        lazy2[l] %= mod;
        lazy2[r] += lazy2[n];
        lazy2[r] %= mod;
      }
      lazy2[n] = 0;
    }
  }
  void build(int n, int  b, int e) {
    lazy1[n] = 0;
    lazy2[n] = 0;
    if (b == e) {
      tree1[n] = a[b];
      tree2[n] = arr[b];
      tree[n] = 1ll * tree1[n] * tree2[n] % mod;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = (tree[l] + tree[r]) % mod;
    tree1[n] = (tree1[l] + tree1[r]) % mod;
    tree2[n] = (tree2[l] + tree2[r]) % mod;
  }
  void upd(int n, int b, int e, int i, int j, int x, int y) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy1[n] += x;
      lazy1[n] %= mod;
      lazy2[n] += y;
      lazy2[n] %= mod;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x, y);
    upd(r, mid + 1, e, i, j, x, y);
    tree[n] = (tree[l] + tree[r]) % mod;
    tree1[n] = (tree1[l] + tree1[r]) % mod;
    tree2[n] = (tree2[l] + tree2[r]) % mod;
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R) % mod;
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  st.build(1, 1, n);

  while (q--) {
    int type, l, r; cin >> type >> l >> r;
    if (type == 1) {
      int x; cin >> x;
      st.upd(1, 1, n, l, r, x, 0);
    }
    else if (type == 2) {
      int x; cin >> x;
      st.upd(1, 1, n, l, r, 0, x);
    }
    else {
      int x = st.query(1, 1, n, l, r);
      assert(x < mod and x >= 0);
      cout << x << '\n';
    }
  }

  return 0;
}