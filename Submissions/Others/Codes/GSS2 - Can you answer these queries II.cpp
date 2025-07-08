#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 200000 + 9, QQ = 200000 + 9;
const ll inf = 1e18;
int  ans[QQ];
vector<pair<int, int>> Q[QQ];

struct ST {
  int tree[4 * N], lazy[4 * N];
  int tree2[4 * N], lazy2[4 * N];
  void push(int n, int b, int e) {
    tree2[n] = max(tree2[n], tree[n] + lazy2[n]);
    tree[n] += lazy[n];
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy2[l] = max(lazy2[l], lazy[l] + lazy2[n]);
      lazy2[r] = max(lazy2[r], lazy[r] + lazy2[n]);

      lazy[l] += lazy[n];
      lazy[r] += lazy[n];
    }
    lazy[n] = 0;
    lazy2[n] = 0;
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] += x;
      lazy2[n] = max(lazy2[n], lazy[n]);
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = max(tree[l], tree[r]);
    tree2[n] = max(tree2[l], tree2[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree2[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
} st;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int q; cin >> q;
  for (int i = 1; i <= q; i++) {
    int l, r; cin >> l >> r;
    Q[r].push_back({l, i});
  }

  map<int, int> mp;
  for (int r = 1; r <= n; r++) {
    st.upd(1, 1, n, mp[a[r]] + 1, r, a[r]);
    mp[a[r]] = r;

    for (auto i : Q[r]) {
      int l = i.first, id = i.second;
      ans[id] = st.query(1, 1, n, l, r);
    }
  }

  for (int i = 1; i <= q; i++) {
    cout << max(0ll, ans[i]) << '\n';
  }

  return 0;
}