#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9, inf = 1e9;
int a[N];

struct ST {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    tree[n] += lazy[n];
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] += lazy[n];
      lazy[r] += lazy[n];
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
    tree[n] = min(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] += x;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = min(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return inf;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return min(L, R);
  }
} st;

int cs;
void solve() {
  int n, q; cin >> n >> q;
  st.build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int to = min(n, i + a[i] - 1);
    st.upd(1, 1, n, i, to, 1);
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << st.query(1, 1, n, i, i) << ' ';
  // }
  // cout << '\n';

  cout << "Case " << ++cs << ":\n";
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int i, x; cin >> i >> x;
      int val = a[i];
      a[i] = x;
      int to = min(n, i + val - 1);
      st.upd(1, 1, n, i, to, -1);
      to = min(n, i + x - 1);
      st.upd(1, 1, n, i, to, 1);
    }
    else {
      int x; cin >> x;
      if (x == 0) {
        cout << "no\n";
        continue;
      }
      if (x > n) {
        cout << "yes\n";
        continue;
      }
      int mn = st.query(1, 1, n, min(n, x), n);
      if (mn > 0 and mn < inf) cout << "yes\n";
      else cout << "no\n";
    }
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