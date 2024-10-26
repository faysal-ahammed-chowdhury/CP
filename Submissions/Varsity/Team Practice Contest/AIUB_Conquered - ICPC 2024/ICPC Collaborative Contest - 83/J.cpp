#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
int a[N];

struct DSU {
  vector<int> par, sz;
  vector<multiset<int>> val;
  int c;
  DSU(int n) {
    par.resize(n + 1), sz.resize(n + 1, 1);
    val.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      par[i] = i;
      val[i] = {(a[i])};
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

    for (auto x : val[j]) {
      val[i].insert(x);
    }

    return i;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  DSU dsu(n);
  while (m--) {
    int u, v; cin >> u >> v;
    ++u, ++v;
    if (!dsu.same(u, v)) dsu.merge(u, v);
  }

  int need = (dsu.count() - 1) * 2;
  if (need > n) {
    cout << "Impossible\n";
    return 0;
  }

  vector<int> v;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (dsu.find(i) == i and need > 0) {
      need--;
      ans += *dsu.val[i].begin();
      dsu.val[i].erase(dsu.val[i].begin());
      for (auto x : dsu.val[i]) {
        v.push_back(x);
      }
    }
  }
  sort(v.begin(), v.end());

  for (int i = 0; i < need; i++) {
    ans += v[i];
  }

  cout << ans << '\n';

  return 0;
}
