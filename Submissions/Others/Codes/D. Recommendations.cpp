#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;

struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = 0; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = max(tree[n], x); 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = max(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return max(L, R); 
  }
} st;

void solve() {
  int n; cin >> n;
  array<int, 3> a[n + 1];
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1];
    v.push_back(a[i][1]);
    a[i][1] = -a[i][1];
    a[i][2] = i;
  }

  sort(a + 1, a + n + 1);

  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  int ans[n + 1];
  map<int, int> mp;

  set<int> se;
  st.build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    a[i][1] = -a[i][1];
    mp[lower_bound(v.begin(), v.end(), a[i][1]) - v.begin() + 1] = a[i][1];
    a[i][1] = lower_bound(v.begin(), v.end(), a[i][1]) - v.begin() + 1;
    auto [x, y, id] = a[i];
    // cout << x << ' ' << y << '\n';

    int here = 0;
    auto it = se.lower_bound(y);
    if (it != se.end()) {
      here += abs(mp[y] - mp[*it]);
      here += abs(x - st.query(1, 1, n, y, n));
    }

    ans[id] = here;

    se.insert(y);
    st.upd(1, 1, n, y, x);

    if (i - 1 >= 1 and a[i][0] == a[i - 1][0] and a[i][1] == a[i - 1][1]) {
      ans[a[i - 1][2]] = 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}