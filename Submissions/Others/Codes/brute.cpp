#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

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


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  vector<array<int, 2>> v;
  while (m--) {
    int a, c; cin >> a >> c;
    v.push_back({c, a});
  }
  sort(v.begin(), v.end());

  DSU dsu(n);
  int ans = 0;
  for (auto [c, a] : v) {
    for (int i = 0; i < n; i++) {
      int v = (i + a) % n;
      if (!dsu.same(i, v)) {
        cout << i << ' ' << v << ' ' << c << '\n';
        dsu.merge(i, v);
        ans += c;
      }
    }
  }
  if (dsu.count() == 1) cout << ans << '\n';
  else cout << -1 << '\n';

  return 0;
}