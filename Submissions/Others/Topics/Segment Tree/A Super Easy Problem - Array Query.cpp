#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e5 + 9;
int a[N];

struct node {
  vector<int> v;
  vector<ll> psum;
  node() {};
  node(vector<int> a, vector<ll> b) {
    v = a;
    psum = b;
  }
};

struct MST { // merge sort tree
  node tree[4 * N];

  node merge(node &a, node &b) {
    int i = 0, j = 0;
    int n = a.v.size(), m = b.v.size();
    node ans;
    while (i < n and j < m) {
      if (a.v[i] <= b.v[j]) {
        ans.v.push_back(a.v[i]);
        i++;
      }
      else {
        ans.v.push_back(b.v[j]);
        j++;
      }
    }
    while (i < n) {
      ans.v.push_back(a.v[i]);
      i++;
    }
    while (j < m) {
      ans.v.push_back(b.v[j]);
      j++;
    }
    for (auto x : ans.v) {
      ans.psum.push_back(x);
    }
    int sz = ans.psum.size();
    for (int i = 1; i < sz; i++) {
      ans.psum[i] += ans.psum[i - 1];
    }
    return ans;
  }

  void build(int n, int b, int e) {
    if (b == e) {
      node v = {{a[b]}, {a[b]}};
      tree[n] = v;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }

  array<ll, 2> query(int n, int b, int e, int i, int j, ll k) {
    if (b > j || e < i) return {0, 0};
    if (b >= i && e <= j) {
      int idx = lower_bound(tree[n].v.begin(), tree[n].v.end(), k) - tree[n].v.begin();
      if (idx == 0) return {0, idx};
      return {tree[n].psum[idx - 1], idx};
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    array<ll, 2> L = query(l, b, mid, i, j, k);
    array<ll, 2> R = query(r, mid + 1, e, i, j, k);
    return {L[0] + R[0], L[1] + R[1]};
  }

  array<ll, 2> query2(int n, int b, int e, int i, int j, ll k) {
    if (b > j || e < i) return {0, 0};
    if (b >= i && e <= j) {
      int idx = tree[n].v.end() - upper_bound(tree[n].v.begin(), tree[n].v.end(), k);
      if (idx == 0) return {0, idx};
      int sz = tree[n].psum.size();
      return {tree[n].psum[sz - 1] - ((sz - idx - 1) < 0 ? 0 : tree[n].psum[sz - idx - 1]), idx};
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    array<ll, 2> L = query2(l, b, mid, i, j, k);
    array<ll, 2> R = query2(r, mid + 1, e, i, j, k);
    return {L[0] + R[0], L[1] + R[1]};
  }
} mst;

int cs;
void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  mst.build(1, 1, n);
  int q; cin >> q;
  cout << "Case " << ++cs << ":\n";
  while (q--) {
    ll i, j, k; cin >> i >> j >> k;
    auto tmp = mst.query(1, 1, n, i, j, k);
    auto tmp2 = mst.query2(1, 1, n, i, j, k);
    ll ans = (1ll * tmp[1] * k) - tmp[0];
    ans += tmp2[0] - (1ll * tmp2[1] * k);
    cout << ans << '\n';
  }
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