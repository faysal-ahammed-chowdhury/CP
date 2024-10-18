#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, inf = 2e9;
int n, m, a[N];

struct MST { // merge sort tree
  vector<int> tree[4 * N];

  vector<int> merge(vector<int> &a, vector<int> &b) {
    int i = 0, j = 0;
    int n = a.size(), m = b.size();
    vector<int> ans;
    while (i < n and j < m) {
      if (a[i] <= b[j]) {
        ans.push_back(a[i]);
        i++;
      }
      else {
        ans.push_back(b[j]);
        j++;
      }
    }
    while (i < n) {
      ans.push_back(a[i]);
      i++;
    }
    while (j < m) {
      ans.push_back(b[j]);
      j++;
    }
    return ans;
  }

  void build(int n, int b, int e) {
    if (b == e) {
      vector<int> v;
      v.push_back(a[b]);
      tree[n] = v;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }

  int query(int n, int b, int e, int i, int j, int p, int q) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) {
      int idx = upper_bound(tree[n].begin(), tree[n].end(), q) - lower_bound(tree[n].begin(), tree[n].end(), p);
      return idx;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j, p, q);
    int R = query(r, mid + 1, e, i, j, p, q);
    return (L + R);
  }

  int query_min(int n, int b, int e, int i, int j, int p, int q) {
    if (b > j || e < i) return inf;
    if (b >= i && e <= j) {
      auto it = lower_bound(tree[n].begin(), tree[n].end(), p);
      if (it == tree[n].end()) return inf;
      if (*it > q) return inf;
      return *it;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query_min(l, b, mid, i, j, p, q);
    int R = query_min(r, mid + 1, e, i, j, p, q);
    return min(L, R);
  }
  int query_max(int n, int b, int e, int i, int j, int p, int q) {
    if (b > j || e < i) return -inf;
    if (b >= i && e <= j) {
      auto it = upper_bound(tree[n].begin(), tree[n].end(), q);
      if (it == tree[n].begin()) return -inf;
      if (*(--it) < p) return -inf;
      return *(it);
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query_max(l, b, mid, i, j, p, q);
    int R = query_max(r, mid + 1, e, i, j, p, q);
    return max(L, R);
  }
} mst;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  mst.build(1, 1, n);

  while (m--) {
    int l, r, p, q; cin >> l >> r >> p >> q;
    int ans1 = mst.query(1, 1, n, l, r, p, q);
    int ans2 = mst.query_min(1, 1, n, l, r, p, q);
    int ans3 = mst.query_max(1, 1, n, l, r, p, q);
    cout << ans1 << ' ';
    cout << (ans2 == inf ? -1 : ans2) << ' ';
    cout << (ans3 == -inf ? -1 : ans3) << '\n';
  }

  return 0;
}