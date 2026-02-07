#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 4e5 + 9, inf = 1e18;
int n, d, a[N];

struct ST {
  int tree[12 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = inf;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = min(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] = min(tree[n], x);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = min(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return inf;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return min(L, R);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> d;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v.push_back(a[i] - d + 1);
    v.push_back(a[i]);
    v.push_back(a[i] + d - 1);
  }

  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  st.build(1, 1, v.size());
  int ans = 0;
  int mn = n + 1;
  for (int i = n; i >= 1; i--) {
    int x = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    int l = lower_bound(v.begin(), v.end(), a[i] - d + 1) - v.begin() + 1;
    int r = lower_bound(v.begin(), v.end(), a[i] + d - 1) - v.begin() + 1;

    int here = st.query(1, 1, v.size(), l, r);
    st.upd(1, 1, v.size(), x, i);

    mn = min(mn, here);
    // cout << i << ' ' << mn << '\n';
    ans += mn - i;
  }

  cout << ans << '\n';

  return 0;
}