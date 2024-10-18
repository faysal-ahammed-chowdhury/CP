#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int n, a[N];

struct ST {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    tree[n] = lazy[n];
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] = lazy[n];
      lazy[r] = lazy[n];
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if (b == e) {
      tree[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] = x;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = max(tree[l], tree[r]);
  }

  int get_first(int n, int b, int e, int l, int r, int x) {
    push(n, b, e);
    if (b > r || e < l) return -1;
    if (tree[n] <= x) return -1;

    if (b == e) return b;

    int tm = b + (e - b) / 2;
    int left = get_first(2 * n, b, tm, l, r, x);
    if (left != -1) return left;
    return get_first(2 * n + 1, tm + 1, e, l , r, x);
  }

  int get_first2(int n, int b, int e, int l, int r, int x) {
    push(n, b, e);
    if (b > r || e < l) return -1;
    if (tree[n] <= x) return -1;

    if (b == e) return b;

    int tm = b + (e - b) / 2;
    int right =  get_first2(2 * n + 1, tm + 1, e, l , r, x);
    if (right != -1) return right;
    return get_first2(2 * n, b, tm, l, r, x);;
  }
} st;

void solve() {
  cin >> n;
  vector<array<int, 2>> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v.push_back({a[i], i});
  }
  sort(v.begin(), v.end());
  st.build(1, 1, n);

  long long ans = 0;

  for (auto [val, idx] : v) {
    int l = st.get_first2(1, 1, n, 1, idx - 1, val - 1);
    int r = st.get_first(1, 1, n, idx + 1, n, val - 1);
    if (l == -1) l = 1;
    else l++;
    if (r == -1) r = n;
    else r--;

    st.upd(1, 1, n, l, idx, val);
    st.upd(1, 1, n, idx, r, val);

    // cout << idx << ' ' << l << ' ' << r << '\n';
    ans += (idx - l);
    ans += (r - idx);
  }
  cout << ans << '\n';
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