#include <bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;

const int N = 2e5 + 9; 
const ll inf = 1e18 + 9; 

bool overflow(ll a, ll b) {
  i128 ans = (i128)a * b;
  return ans >= inf; 
}

struct ST {
  ll tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if(lazy[n] == 1) return;
    tree[n] = overflow(tree[n], lazy[n]) ? inf : tree[n] * lazy[n];

    if(b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] = overflow(lazy[l], lazy[n]) ? inf : lazy[l] * lazy[n]; 
      lazy[r] = overflow(lazy[r], lazy[n]) ? inf : lazy[r] * lazy[n]; 
    }
    lazy[n] = 1;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 1;
    if(b == e) {
      tree[n] = 1; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = overflow(tree[l], tree[r]) ? inf : tree[l] * tree[r]; 
  }
  void upd(int n, int b, int e, int i, int j, ll x) {
    push(n, b, e);
    if(b > j || e < i) return;
    if(b >= i && e <= j) {
      lazy[n] = overflow(lazy[n], x) ? inf : lazy[n] * x; 
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = overflow(tree[l], tree[r]) ? inf : tree[l] * tree[r]; 
  }
  ll query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return 1;
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    ll L = query(l, b, mid, i, j);
    ll R = query(r, mid + 1, e, i, j);
    return overflow(L, R) ? inf : L * R;
  }
} st;

int cs;
void solve() {
  int n, q; cin >> n >> q;
  ll a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st.build(1, 1, n);
  while (q--) {
    ll l, r, m; cin >> l >> r >> m;
    st.upd(1, 1, n, l, r, m);
  }
  cout << "Case " << ++cs << ": ";
  for (int i = 1; i <= n; i++) {
    ll x = st.query(1, 1, n, i, i);
    // cout << x << ' ';
    assert(x != 0);
    if (x >= inf) cout << 0 << ' ';
    else cout << a[i] / x << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}