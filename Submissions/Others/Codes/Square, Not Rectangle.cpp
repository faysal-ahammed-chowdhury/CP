#include <bits/stdc++.h>
using namespace std;

const int N = 300005, inf = 2e9;
int a[N];

struct ST {
  int tree[4 * N];
  void build(int n, int  b, int e) {
    if (b == e) {
      tree[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = min(tree[l], tree[r]);
  }
  int get_first(int n, int b, int e, int l, int r, int x) {
    if (b > r || e < l) return -1;
    if (tree[n] >= x) return -1;

    if (b == e) return b;

    int tm = b + (e - b) / 2;
    int left = get_first(2 * n, b, tm, l, r, x);
    if (left != -1) return left;
    return get_first(2 * n + 1, tm + 1, e, l , r, x);
  }
  int get_last(int n, int b, int e, int l, int r, int x) {
    if (b > r || e < l) return -1;
    if (tree[n] >= x) return -1;

    if (b == e) return b;

    int tm = b + (e - b) / 2;
    int right = get_last(2 * n + 1, tm + 1, e, l , r, x);
    if (right != -1) return right;
    return get_last(2 * n, b, tm, l, r, x);
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

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int height = a[i];

    int right = i, left = i;
    int tmp = st.get_first(1, 1, n, i, n, a[i]);
    right = (tmp == -1 ? n : tmp  - 1);
    tmp = st.get_last(1, 1, n, 1, i, a[i]);
    left = (tmp == -1 ? 1 : tmp + 1);

    int width = right - left + 1;
    ans = max(ans, min(height, width));
  }

  cout << ans << '\n';

  return 0;
}