#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3e5 + 9, K = 12, inf = 1e18;
int n, k, a[N], dp[N][K];

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
    tree[n] = min(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return inf;
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return min(L, R); 
  }
} st;

int fun(int i, int rem) {
  if (i >= n + 1) return 0;
  int &ans = dp[i][rem];
  if (ans != -1) return ans;
  ans = a[i] + fun(i + 1, rem);
  for (int x = 1; x <= rem; x++) {
    int mn = st.query(1, 1, n, i, i + x);
    int len = x + 1;
    int val = mn * len;
    ans = min(ans, val + fun(i + x + 1, rem - x));
  }
  return ans;
}

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st.build(1, 1, n);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = -1;
    }
  }
  cout << fun(1, k) << '\n';
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