#include <bits/stdc++.h>
using namespace std;

const int N = 20005, K = 12, mod = 1e9;
int n, k, a[N], dp[N][K];

struct node {
  int count[K];
};

node merge(node l, node r) {
  node ans;
  for (int i = 1; i < K; i++) {
    ans.count[i] = (l.count[i] + r.count[i]) % mod;
  }
  return ans;
}

node tree[4 * N + 5];
struct ST {
  ST() {
    memset(tree, 0, sizeof(tree));
  }
  void build(int n, int b, int e) {
    if (b == e) {
      for (int i = 0; i < K; i++) {
        tree[n].count[i] = 0;
      }
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int k, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n].count[k] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, k, x);
    upd(r, mid + 1, e, i, k, x);
    tree[n] = merge(tree[l], tree[r]);
  }
  node query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) {
      node tmp;
      for (int i = 0; i < K; i++) {
        tmp.count[i] = 0;
      }
      return tmp;
    }
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, N);
  for (int i = 1; i <= n; i++) {
    for (int len = 1; len <= k; len++) {
      if (len == 1) {
        dp[i][1] = 1;
        st.upd(1, 1, N, a[i], 1, 1);
      }
      else {
        int &ans = dp[i][len];
        // for (int j = 1; j < i; j++) {
        //   if (a[j] > a[i]) {
        //     ans += dp[j][len - 1];
        //   }
        // }
        ans += st.query(1, 1, N, a[i] + 1, N - 1).count[len - 1];
        ans %= mod;
        st.upd(1, 1, N, a[i], len, dp[i][len]);
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += dp[i][k];
    ans %= mod;
  }
  cout << ans << '\n';

  return 0;
}