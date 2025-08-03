#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, mod = 1e9 + 7;
int a[N], dp[N];

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
      tree[n] = (tree[n] + x) % mod; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = (tree[l] + tree[r]) % mod;
  }
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0; 
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R) % mod;
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
  }

  st.build(1, 1, n);

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = (1 + st.query(1, 1, n, 1, a[i] - 1)) % mod;
    st.upd(1, 1, n, a[i], dp[i]);
    ans = (ans + dp[i]) % mod;
  }

  cout << ans << '\n';

  return 0;
}