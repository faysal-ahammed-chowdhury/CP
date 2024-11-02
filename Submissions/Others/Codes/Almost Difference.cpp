#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 9;
int a[N];
#define int __int128

struct ST2 {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r];
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
    tree[n] = tree[l] + tree[r];
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R);
  }
} st2, st3;

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
  int get_first(int n, int b, int e, int l, int r, int x) {
    if (b > r || e < l) return -1;
    if (tree[n] <= x) return -1;

    if (b == e) return b;

    int tm = b + (e - b) / 2;
    int left = get_first(2 * n, b, tm, l, r, x);
    if (left != -1) return left;
    return get_first(2 * n + 1, tm + 1, e, l , r, x);
  }
} st;

void print(__int128 x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int32_t n; cin >> n;
  int32_t b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  st.build(1, 1, n);
  st2.build(1, 1, n);
  st3.build(1, 1, n);
  map<int, queue<int>> mp;
  for (int i = 1; i <= n; i++) {
    mp[b[i]].push(i);
  }
  // for (auto [x, q] : mp) {
  //   cout << x << ": ";
  //   while (!q.empty()) {
  //     cout << q.front() << ' ';
  //     q.pop();
  //   }
  //   cout << '\n';
  // }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int idx = mp[a[i]].front();
    mp[a[i]].pop();
    st.upd(1, 1, n, idx, a[i]);
    st2.upd(1, 1, n, idx, a[i]);
    st3.upd(1, 1, n, idx, 1);
    int x1 = a[i] - 2, x2 = a[i] + 1;
    int idx1 = st.get_first(1, 1, n, 1, n, x1);
    idx1--;
    int idx2 = st.get_first(1, 1, n, 1, n, x2);
    int sum1 = 0, cnt1 = 0;
    if (idx1 > 0) {
      sum1 = st2.query(1, 1, n, 1, idx1);
      cnt1 = st3.query(1, 1, n, 1, idx1);
    }
    int sum2 = 0, cnt2 = 0;
    if (idx2 > 0) {
      sum2 = st2.query(1, 1, n, idx2, n);
      cnt2 = st3.query(1, 1, n, idx2, n);
    }
    if (cnt1) ans += (a[i] * cnt1) - sum1;
    if (cnt2) ans += (a[i] * cnt2) - sum2;
  }
  print(ans);

  return 0;
}