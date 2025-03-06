#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
const ll inf = 1e18;
int a[N];
ll pref[N], suff[N];

struct node {
  ll mx, mn;
  int mx_idx, mn_idx;
};

node merge(node l, node r) {
  if (l.mn == inf) return r;
  if (r.mn == inf) return l;

  node ans;
  ans.mx = max(l.mx, r.mx);
  if (l.mx > r.mx) ans.mx_idx = l.mx_idx;
  else ans.mx_idx = r.mx_idx;

  ans.mn = min(l.mn, r.mn);
  if (l.mn < r.mn) ans.mn_idx = l.mn_idx;
  else ans.mn_idx = r.mn_idx;

  return ans;
}

struct ST {
  node tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = {pref[b], pref[b], b, b}; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]); 
  }
  node query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return {-inf, inf};
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R);
  }
} st;

struct ST2 {
  node tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = {suff[b], suff[b], b, b}; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]); 
  }
  node query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return {-inf, inf};
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R);
  }
} st2;

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }

  suff[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    suff[i] = suff[i + 1] + a[i];
  }

  int q; cin >> q;

  st.build(1, 1, n);
  st2.build(1, 1, n);

  while (q--) {
    int l, r; cin >> l >> r;
    auto tmp1 = st.query(1, 1, n, l, r);
    auto tmp2 = st2.query(1, 1, n, l, r);

    ll ans1 = abs((tmp1.mx - pref[l - 1]) - (tmp2.mn - suff[r + 1]));
    ll ans2 = abs((tmp1.mn - pref[l - 1]) - (tmp2.mx - suff[r + 1]));

    // cout << ans1 << ' ' << ans2 << '\n';

    // cout << tmp2.mx_idx << '\n';

    if (ans1 >= ans2) {
      cout << tmp1.mx_idx << ' ' << tmp2.mn_idx << '\n'; 
    }
    else {
      cout << tmp1.mn_idx << ' ' << tmp2.mx_idx << '\n'; 
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}