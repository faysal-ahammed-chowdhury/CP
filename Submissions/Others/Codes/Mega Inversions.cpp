#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
int a[N], cnt_small[N], cnt_big[N];

struct ST {
  int tree[4 * N];
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
      tree[n] += x;
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    cnt_big[i] = st.query(1, 1, n, a[i] + 1, n);
    st.upd(1, 1, n, a[i], 1);
  }

  st.build(1, 1, n);
  for (int i = n; i >= 1; i--) {
    cnt_small[i] = st.query(1, 1, n, 1, a[i] - 1);
    st.upd(1, 1, n, a[i], 1);
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += 1ll * cnt_small[i] * cnt_big[i];
  }
  cout << ans << '\n';

  return 0;
}