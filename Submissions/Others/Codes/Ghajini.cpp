#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, inf = 1e9;
int a[N];

struct ST {
  pair<int, int> tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = make_pair(a[b], a[b]);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n].first = max(tree[l].first, tree[r].first); 
    tree[n].second = min(tree[l].second, tree[r].second); 
  }
  pair<int, int> query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return make_pair(-inf, inf); 
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, i, j);
    pair<int, int> R = query(r, mid + 1, e, i, j);
    return make_pair(max(L.first, R.first), min(L.second, R.second));
  }
} st;

int cs;
void solve() {
  int n, d; cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st.build(1, 1, n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    pair<int, int> x = st.query(1, 1, n, i, i + d - 1);
    ans = max(ans, x.first - x.second);
  }
  cout << "Case " << ++cs << ": " << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}