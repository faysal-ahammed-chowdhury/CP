#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }

const int N = 1e5 + 9, K = 20;
int n, q;
int a[N];
int pref[K][N];

struct ST {
  int tree[4 * N];
  void build(int n, int  b, int e, int bit) {
    if (b == e) {
      tree[n] = CHECK(a[b], bit);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid, bit);
    build(r, mid + 1, e, bit);
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
    return get_last(2 * n, b, tm, l, r, x);;
  }
} st[K];

int f(int l, int r, int k) {
  int ans = 0;
  for (int i = K - 1; i >= 0; i--) {
    int x = pref[i][k] - pref[i][l - 1];
    int y = pref[i][r] - pref[i][k];
    if (x == (k - l + 1)) {
      ans += (1ll << i);
    }
    if (y == (r - (k + 1) + 1)) {
      ans += (1ll << i);
    }
  }
  return ans;
}

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int k = 19; k >= 0; k--) {
    st[k].build(1, 1, n, k);
    for (int i = 1; i <= n; i++) {
      pref[k][i] = pref[k][i - 1] + CHECK(a[i], k);
    }
  }

  while (q--) {
    int l, r; cin >> l >> r;
    int ans = 0;
    for (int k = 0; k < K; k++) {
      int x = st[k].get_first(1, 1, n, l, r, 1);
      --x;
      if (x >= l and x < r) {
        ans = max(ans, f(l, r, x));
      }
    }
    ans = max(ans, f(l, r, l));
    ans = max(ans, f(l, r, r - 1));

    cout << ans << '\n';
  }
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