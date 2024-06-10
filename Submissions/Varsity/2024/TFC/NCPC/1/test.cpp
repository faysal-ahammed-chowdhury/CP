#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 9;
int a[N];

struct ST {
  int tree[4 * N];
  ST() {
    memset(tree, 0, sizeof(tree));
  }
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = a[b];
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
} st1;

struct ST2 {
  int tree[4 * 4 * N];
  ST2() {
    memset(tree, 0, sizeof(tree));
  }
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
} st2;

int my_round(int x) {
  if (x % 10) return 10 * (x / 10 + 1);
  return x;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int z = n * 2 + 1;
  st1.build(1, 1, n);
  st2.build(1, 1, z);
  map<pair<int, int>, int> mp;
  mp[ {0, n + 1}] = 1;
  set<pair<int, int>> se;
  se.insert({0, n + 1});
  int ans = my_round(st1.query(1, 1, n, 1, n));
  st2.upd(1, 1, z, 1, ans);
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;

    auto it = --se.upper_bound({x, 0});
    int f = (*it).first;
    int l = (*it).second;
    se.erase({f, l});
    int id = mp[ {f, l}];
    st1.upd(1, 1, n, x, 0);
    st2.upd(1, 1, z, id, 0);

    if (f != l) {
      int id1 = id * 2;
      mp[ {f, x - 1}] = id1;
      se.insert({f, x - 1});
      int sum1 = st1.query(1, 1, n, f, x);
      sum1 = my_round(sum1);
      st2.upd(1, 1, z, id1, sum1);

      int id2 = id * 2 + 1;
      mp[ {x + 1, l}] = id2;
      se.insert({x + 1, l});
      int sum2 = st1.query(1, 1, n, x, l);
      sum2 = my_round(sum2);
      st2.upd(1, 1, z, id2, sum2);
    }

    ans = max(ans, (i + 1) * st2.query(1, 1, z, 1, z));
  }

  cout << ans << '\n';

  return 0;
}