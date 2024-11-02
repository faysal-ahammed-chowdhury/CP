#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100005;
int a[N];

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
      tree[n] = {a[b]};
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
      int idx = upper_bound(tree[n].begin(), tree[n].end(), k) - tree[n].begin();
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

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  
  mst.build(1, 1, n);
  while (q--) {
    int i, j, k; cin >> i >> j >> k;
    int l = -1e9, r = 1e9, ans = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (mst.query(1, 1, n, i, j, mid) >= k) {
        ans = mid;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
