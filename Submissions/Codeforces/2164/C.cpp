#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6 + 100, inf = 1e18;
int n, m, a[N], b[N], c[N];

struct ST {
  pair<int, int> tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = { -1, b};
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
      tree[n].first = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = max(tree[l], tree[r]);
  }
  pair<int, int> query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return { -inf, -inf};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, i, j);
    pair<int, int> R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
} st;


void solve() {
  cin >> n >> m;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v.push_back(a[i]);
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    v.push_back(b[i]);
  }
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
    if (c[i] != 0) v.push_back(c[i]);
  }

  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  int mx = v.size() + 10;
  st.build(1, 1, mx);

  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
  }
  sort(a + 1, a + n + 1);


  map<int, multiset<int, greater<int>>> mp;
  vector<int> health_0;
  for (int i = 1; i <= m; i++) {
    b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin() + 1;
    if (c[i] != 0) c[i] = lower_bound(v.begin(), v.end(), c[i]) - v.begin() + 1;
    else health_0.push_back(b[i]);

    mp[b[i]].insert(c[i]);
  }
  sort(health_0.begin(), health_0.end());

  for (auto [life, ms] : mp) {
    // cout << life << ' ' << *ms.begin() << '\n';
    st.upd(1, 1, mx, life, *ms.begin());
  }

  int ans = 0, idx = 0;
  for (int i = 1; i <= n; i++) {
    int cur = a[i];
    while (true) {
      auto [add, health] = st.query(1, 1, mx, 1, cur);
      if (add <= 0) break;
      mp[health].erase(mp[health].find(add));
      int val = -100;
      if (mp[health].size() == 0) val = -1;
      else val = *mp[health].begin();
      assert(val >= -1);
      st.upd(1, 1, mx, health, val);
      ans++;
      cur = max(cur, add);
      a[i] = cur;
      if (idx < health_0.size()) {
        if (cur >= health_0[idx]) {
          idx++;
          break;
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    int cur = a[i];
    while (true) {
      auto [add, health] = st.query(1, 1, mx, 1, cur);
      if (add <= -1) break;
      mp[health].erase(mp[health].find(add));
      int val = -100;
      if (mp[health].size() == 0) val = -1;
      else val = *mp[health].begin();
      assert(val >= -1);
      st.upd(1, 1, mx, health, val);
      ans++;
      cur = max(cur, add);

      if (add == 0) cur = add;
      else cur = max(cur, add);
    }
  }

  assert(ans <= m);
  cout << ans << '\n';
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