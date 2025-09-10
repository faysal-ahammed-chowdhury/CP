#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;

const int N = 1e5 + 9;
int n, q;
int a[N], ans[N], nxt[N];

struct ST {
  pair<int, int> tree[4 * N];
  void build(int n, int  b, int e) {
    if (b == e) {
      tree[n] = {a[b], b};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
  }
  pair<int, int> query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return {0, 0};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, i, j);
    pair<int, int> R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
  int get_first(int n, int b, int e, int i, int j, int x) {
    if (b > j || e < i) return -1;
    if (tree[n].first <= x) return -1;
    if (b == e) return b;
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int left = get_first(l, b, mid, i, j, x);
    if (left != -1) return left;
    return get_first(r, mid + 1, e, i , j, x);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    nxt[i] = st.get_first(1, 1, n, i + 1, n, a[i]);
  }

  for (int i = n; i >= 1; i--) {
    ans[i] = 1;
    if (nxt[i] != -1) {
      ans[i] += ans[nxt[i]];
    }
  }

  while (q--) {
    int l, r; cin >> l >> r;
    int tmp = ans[l];
    int idx = st.query(1, 1, n, l, r).second;
    if (nxt[idx] != -1) {
      tmp -= ans[nxt[idx]];
    }

    cout << tmp << '\n';
  }

  return 0;
}