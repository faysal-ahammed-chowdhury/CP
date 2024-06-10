#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, M = 6e5 + 9;
int a[N], l[N], r[N];
char type[N];

struct ST {
  int tree[4 * M];
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] += x;
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
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v.push_back(a[i]);
  }

  for (int i = 1; i <= q; i++) {
    cin >> type[i] >> l[i] >> r[i];
    if (type[i] == '?') {
      v.push_back(l[i]);
    }
    v.push_back(r[i]);
  }

  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
  }
  for (int i = 1; i <= q; i++) {
    if (type[i] == '?') {
      l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin() + 1;
    }
    r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin() + 1;
  }

  for (int i = 1; i <= n; i++) {
    st.upd(1, 1, M, a[i], 1);
  }

  for (int i = 1; i <= q; i++) {
    if (type[i] == '!') {
      int k = l[i], x = r[i];
      st.upd(1, 1, M, x, +1);
      st.upd(1, 1, M, a[k], -1);
      a[k] = x;
    }
    else {
      cout << st.query(1, 1, M, l[i], r[i]) << '\n';
    }
  }

  return 0;
}