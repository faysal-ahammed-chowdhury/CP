#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, M = 1e5 + 9, inf = 1e9;
int a[N], dp[N], dp2[N];

struct ST {
  int tree[4 * M];
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
      tree[n] = max(tree[n], x);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = max(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return -inf;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      mp[a[i]]++;
    }
    int id = 0;
    for (auto x : mp) {
      mp[x.first] = ++id;
    }
    for (int i = 1; i <= n; i++) {
      a[i] = mp[a[i]];
    }

    st.build(1, 1, M);

    for (int i = 1; i <= n; i++) {
      dp[i] = 1;
      if (a[i] != 1) {
        int mx = st.query(1, 1, M, 1, a[i] - 1);
        mx++;
        dp[i] = max(dp[i], mx);
      }
      st.upd(1, 1, M, a[i], dp[i]);
    }

    st.build(1, 1, M);

    for (int i = n; i >= 1; i--) {
      dp2[i] = 1;
      if (a[i] != 1) {
        int mx = st.query(1, 1, M, 1, a[i] - 1);
        mx++;
        dp2[i] = max(dp2[i], mx);
      }
      st.upd(1, 1, M, a[i], dp2[i]);
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
      ans = max(ans, 2 * min(dp[i], dp2[i]) - 1);
    }
    cout << ans << '\n';
  }

  return 0;
}