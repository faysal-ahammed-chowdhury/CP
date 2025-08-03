#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
int a[N];
ll dp[N][15], arr[15];

struct node {
  ll cnt[15];
};

node merge(node &l, node &r) {
  node tmp;
  for (int i = 0; i <= 11; i++) {
    tmp.cnt[i] = l.cnt[i] + r.cnt[i];
  }
  return tmp;
}

struct ST {
  node tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      for (int val = 0; val <= 11; val++) {
        tree[n].cnt[val] = 0;
      }
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      for (int val = 1; val <= 11; val++) {
        tree[n].cnt[val] = arr[val];
      }
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i);
    upd(r, mid + 1, e, i);
    tree[n] = merge(tree[l], tree[r]);
  }
  node query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) {
      node tmp;
      for (int val = 0; val <= 11; val++) {
        tmp.cnt[val] = 0;
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

  int n, k; cin >> n >> k;
  k++;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);

  for (int i = 1; i <= n; i++) {
    dp[i][1] = 1;
    auto tmp = st.query(1, 1, n, 1, a[i] - 1);
    for (int val = 2; val <= 11; val++) {
      dp[i][val] = tmp.cnt[val - 1];
      arr[val] = dp[i][val];
    }
    arr[1] = 1;
    st.upd(1, 1, n, a[i]);
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += dp[i][k];
  }

  cout << ans << '\n';

  return 0;
}