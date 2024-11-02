#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, M = 1e5 + 9;
int a[N], dp[N];

struct ST {
  int tree[4 * (M + 2)];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = max(tree[n], x);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = max(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
} st;

void solve() {
  int n, m, p; cin >> n >> m >> p;
  pair<int, int> arr[p + 1];
  for (int i = 1; i <= p; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  sort(arr + 1, arr + p + 1);
  for (int i = 1; i <= p; i++) {
    a[i] = arr[i].second;
    a[i] += 2;
  }

  st.build(1, 1, M);

  for (int i = 1; i <= p; i++) {
    dp[i] = 1;
    if (a[i] != 1) {
      int mx = st.query(1, 1, M, 1, a[i]);
      mx++;
      dp[i] = max(dp[i], mx);
    }
    st.upd(1, 1, M, a[i], dp[i]);
  }

  int ans = 0;
  for (int i = 1; i <= p; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
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