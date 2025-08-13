#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
vector<int> a[N];

struct MST {
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
      for (auto x : a[b]) tree[n].push_back(x);
      sort(tree[n].begin(), tree[n].end());
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }

  int query(int n, int b, int e, int i, int j, int k) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) {
      int idx = tree[n].end() - lower_bound(tree[n].begin(), tree[n].end(), k);
      return idx;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j, k);
    int R = query(r, mid + 1, e, i, j, k);
    return (L + R);
  }
} mst;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int l, r; cin >> l >> r;
    a[l].push_back(r);
  }

  mst.build(1, 1, 1e6);
  while (m--) {
    int cnt; cin >> cnt;
    int last = 0, ans = 0;
    for (int i = 1; i <= cnt; i++) {
      int x; cin >> x;
      ans += mst.query(1, 1, 1e6, last + 1, x, x);
      last = x;
    }

    cout << ans << '\n';
  }

  return 0;
}
