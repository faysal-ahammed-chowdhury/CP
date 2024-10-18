#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9, inf = 2e9;
int n, m, a[N], disc[N], finish[N], timer;
vector<int> g[N];

void dfs(int u, int p) {
  disc[u] = ++timer;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  finish[u] = timer;
}

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

  cin >> n >> m;
  for (int i = 2; i <= n; i++) {
    int p; cin >> p;
    g[i].push_back(p);
    g[p].push_back(i);
  }

  dfs(1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[disc[i]];
  }

  mst.build(1, 1, n);

  while (m--) {
    int i, x; cin >> i >> x;
    int l = disc[i], r = finish[i];
    cout << mst.query(1, 1, n, l, r, x) << '\n';
  }

  return 0;
}