#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int n, a[N];

struct node {
  int mx, mx_cnt, mx2, mx2_cnt;
};

node merge(node &l, node &r) {
  map<int, int, greater<int>> mp;
  mp[l.mx] += l.mx_cnt;
  mp[l.mx2] += l.mx2_cnt;
  mp[r.mx] += r.mx_cnt;
  mp[r.mx2] += r.mx2_cnt;
  vector<pair<int, int>> v;
  for (auto [mx, cnt] : mp) {
    v.push_back({mx, cnt});
  }
  node ans = {v[0].first, v[0].second, 0, 0};
  if (v.size() > 1) {
    ans.mx2 = v[1].first;
    ans.mx2_cnt = v[1].second;
  }
  return ans;
}

struct ST {
  node tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = {a[b], 1, 0, 0};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = {x, 1, 0, 0}; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = merge(tree[l], tree[r]);
  }
  node query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return {0, 0, 0, 0};
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R); // change this
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int p, x; cin >> p >> x;
      st.upd(1, 1, n, p, x);
    }
    else {
      int l, r; cin >> l >> r;
      node ans = st.query(1, 1, n, l, r);
      cout << ans.mx2_cnt << '\n';
    }
  }

  return 0;
}