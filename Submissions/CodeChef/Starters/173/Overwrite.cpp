#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 9, inf = 1e18;

struct ST {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    tree[n] = lazy[n] * (e - b + 1);
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
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r];
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
    tree[n] = tree[l] + tree[r];
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return L + R;
  }
} st;

void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1], b[m + 1], arr[m + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  int mn = inf, idx = -1;
  for (int j = 1; j <= m; j++) {
    cin >> arr[j];
    if (arr[j] < mn) {
      mn = arr[j];
      idx = j;
    }
  }

  int idxx = 1;
  for (int j = idx; j <= m; j++, idxx++) b[idxx] = arr[j];
  for (int j = 1; j < idx; j++, idxx++) b[idxx] = arr[j];

  st.build(1, 1, n);

  for (int i = 1; i + m - 1 <= n; i++) {
    if (st.query(1, 1, n, i, i)) {
      st.upd(1, 1, n, i, i + m - 1, i);
    }
    else if (a[i] > b[1]) {
      st.upd(1, 1, n, i, i + m - 1, i);
    }
  }

  idx = n - m + 1;
  if (st.query(1, 1, n, idx, idx) == 0 and a[idx] == b[1]) {
    bool done = false;
    bool first = false;
    for (int i = idx, j = 1; i <= n; i++, j++) {
      if (done) {
        if (!first) a[i] = b[j];
        continue;
      }
      if (a[i] > b[j]) {
        done = true;
        a[i] = b[j];
        first = false;
      }
      else if (b[j] > a[i]) {
        done = true;
        first = true;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    int idx = st.query(1, 1, n, i, i);
    if (idx == 0) cout << a[i] << ' ';
    else {
      int idxx = i - idx + 1;
      cout << b[idxx] << ' ';
    }
  }
  cout << '\n';
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