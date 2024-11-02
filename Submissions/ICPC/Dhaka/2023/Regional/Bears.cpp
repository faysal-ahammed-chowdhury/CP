#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int dp[N];

struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = max(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
} st;

int cs;
void solve() {
  int n; cin >> n;
  map<int, vector<int>> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    for (int j = 1; j * j <= x; j++) {
      if (x % j == 0) {
        mp[j].push_back(x / j);
      }
    }
  }

  for (int i = 0; i <= n; i++) {
    dp[i] = 0;
  }
  st.build(1, 1, n);
  int ans = 0;
  for (auto [_, v] : mp) {
    for (auto x : v) {
      int mx = dp[x];
      mx = max(mx, 1 + st.query(1, 1, n, 1, x - 1));
      dp[x] = mx;
      ans = max(ans, dp[x]);
    }
    for (auto x : v) {
      st.upd(1, 1, n, x, dp[x]);
    }
  }

  cout << "Case " << ++cs << ": " << ans << '\n';
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