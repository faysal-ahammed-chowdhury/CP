#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
const ll inf = 1e18;
int a[N];
 
ll get(ll a, ll p, ll n) { //  arithmetic sum
  ll x = (1ll * (a + p) * n) / 2;
  return x;
}
 
struct ST {
  ll tree[4 * N];
  array<ll, 3> lazy[4 * N]; // first element, last element, difference
  void push(int n, int b, int e) {
    int len = e - b + 1;
    if (lazy[n][2] == 0) return;
    tree[n] += get(lazy[n][0], lazy[n][1], (lazy[n][1] - lazy[n][0]) / lazy[n][2] + 1);
    if (b != e) {
      int l = n << 1, r = l + 1;
      ll first = lazy[n][0];
      ll last = first + (1ll * (((len + 1) / 2) - 1) * lazy[n][2]); // a + (n - 1) * d
      lazy[l][0] += first;
      lazy[l][1] += last;
      lazy[l][2] += lazy[n][2];
 
      lazy[r][0] += last + lazy[n][2];
      lazy[r][1] += lazy[n][1];
      lazy[r][2] += lazy[n][2];
    }
    lazy[n] = {0, 0, 0};
  }
  void build(int n, int  b, int e) {
    lazy[n] = {0, 0, 0};
    if (b == e) {
      tree[n] = a[b]; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r];
  }
  void upd(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      int start = b - i + 1;
      int last = start + (e - b);
      lazy[n] = {start, last, 1}; 
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j);
    upd(r, mid + 1, e, i, j);
    tree[n] = tree[l] + tree[r]; 
  }
  ll query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    ll L = query(l, b, mid, i, j);
    ll R = query(r, mid + 1, e, i, j);
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
    int type; cin >> type;
    if (type == 1) {
      int l, r; cin >> l >> r;
      st.upd(1, 1, n, l, r);
    }
    else {
      int l, r; cin >> l >> r;
      cout << st.query(1, 1, n, l, r) << '\n';
    }
  }
 
  return 0;
}