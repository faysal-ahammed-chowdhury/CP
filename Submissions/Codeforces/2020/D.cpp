#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> par, sz;
  int c;
  DSU(int n) {
    par.resize(n + 1), sz.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) {
      par[i] = i;
    }
    c = n;
  }
  int find(int i) {
    return (i == par[i] ? i : par[i] = find(par[i]));
  }
  bool same(int i, int j) {
    return find(i) == find(j);
  }
  int get_size(int i) {
    return sz[find(i)];
  }
  int count() { // number of connected components
    return c;
  }
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return -1;
    c--;
    if (sz[i] < sz[j]) swap(i, j);
    par[j] = i;
    sz[i] += sz[j];
    return i;
  }
};

const int N = 2e5 + 9;

vector<array<int, 2>> simplify(vector<array<int, 2>> &a) {
  vector<array<int, 2>> ans;
  sort(a.begin(), a.end());
  int n = a.size();
  for (int i = 0, j; i < n; i++) {
    auto &[l1, r1] = a[i];
    for (j = i + 1; j < n; j++) {
      auto &[l2, r2] = a[j];
      if (l2 > r1) break;
      r1 = max(r1, r2);
    }
    ans.push_back({l1, r1});
    i = j - 1;
  }
  return ans;
}

void solve() {
  int n, m; cin >> n >> m;
  vector<array<int, 2>> at[12][12];
  while (m--) {
    int a, d, k; cin >> a >> d >> k;
    at[d][(a % d == 0 ? 10 : a % d)].push_back({a, a + d * k});
  }
  DSU dsu(n);
  for (int d = 1; d <= 10; d++) {
    for (int j = 1; j <= 10; j++) {
      auto a = at[d][j];
      if (a.empty()) continue;
      a = simplify(a);
      for (auto [l, r] : a) {
        for (int i = l; i <= r; i += d) {
          dsu.merge(l, i);
        }
      }
    }
  }
  cout << dsu.count() << '\n';
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