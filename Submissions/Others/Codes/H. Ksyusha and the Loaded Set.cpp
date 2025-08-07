#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 9;
int a[N];

struct ST {
  int tree[4 * (N + 2)];
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
  int get_first(int n, int b, int e, int i, int j, int x) {
    if (b > j || e < i) return -1;
    if (tree[n] < x) return -1;

    if (b == e) return b;

    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int left = get_first(l, b, mid, i, j, x);
    if (left != -1) return left;
    return get_first(r, mid + 1, e, i , j, x);
  }
} st;

void solve() {
  int n; cin >> n;

  set<int> se;
  se.insert(1);
  se.insert(5e6);

  auto insert = [&](int x) {
    int nxt = *se.upper_bound(x);
    int prv = *prev(se.upper_bound(x));
    st.upd(1, 1, N, prv, x - prv - 1);
    st.upd(1, 1, N, x, nxt - x - 1);
    se.insert(x);
  };

  auto erase = [&](int x) {
    se.erase(x);
    int nxt = *se.upper_bound(x);
    int prv = *prev(se.upper_bound(x));
    st.upd(1, 1, N, prv, nxt - prv - 1);
    st.upd(1, 1, N, x, 0);
  };
  
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i]++;
    insert(a[i]);
  }

  int q; cin >> q;
  while (q--) {
    char T; cin >> T;
    int k; cin >> k;
    if (T == '+') {
      k++;
      insert(k);
    }
    else if (T == '-') {
      k++;
      erase(k);
    }
    else {
      int idx = st.get_first(1, 1, N, 1, N, k);
      cout << idx << ' ';
    }
  }
  cout << '\n';

  for (auto x : se) {
    st.upd(1, 1, N, x, 0);
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