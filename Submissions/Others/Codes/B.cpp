#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 9;
int a[N];

struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = __gcd(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return __gcd(L, R);
  }
} st;


void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st.build(1, 1, n);
  int ans = 0;
  for (int len = 1; len <= n; len++) {
    int mx = 0;
    for (int i = 1; i + len - 1 <= n; i++) {
      mx = st.query(1, 1, n, i, i + len - 1);
    }
    ans = max(ans, len * mx);
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  cin.ignore();
  while(t--) {
    solve();
  }

  return 0;
}